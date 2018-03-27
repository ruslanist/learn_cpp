#include <utils.h>

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int read_stream(FILE * f, char ** output) {
    int retval = -1;
    char * read_buffer = NULL;
    size_t read_buffer_size = 1024;

    if(output == NULL || f == NULL) {
        LOG("read_stream: bad input params");
        goto on_err;
    }

    read_buffer = malloc(read_buffer_size);
    if(read_buffer == NULL) {
        LOG("malloc fail");
        goto on_err;
    }

    /*
     * We must read user input with arbitrary length.
     * So, at first we create a buffer with fixed size: read_buffer.
     * In the next for loop we will check: do we have enough place for incoming user input?
     * If not, we do realloc and resize read_buffer and add new value in read_buffer_size
     */
    size_t read_pos = 0;
    for(; read_pos < read_buffer_size; read_pos++) {
        char ch = fgetc(f);

        if(ch == EOF) {
            LOG("stdin fail");
            goto on_err;
        }
        //He we must break, because a user press Enter. That means the end of a command. We do not need to read more from user
        if(ch == '\n') {
            read_buffer[read_pos] = '\0'; //We end our buffer with user command with null terminator. Because each c-string must ends with null terminator
            //After this, we will be able to safe put read_buffer as argument to printf and other c-string functions.
            break;
        }

        read_buffer[read_pos] = ch;

        //if it a last iteration, and we need a more space, we realloc read_buffer
        if((read_pos + 1) == read_buffer_size) {
            size_t new_size = read_buffer_size * 2;
            char * tmp = realloc(read_buffer, new_size);

            if(tmp == NULL) {
                LOG("realloc fail");
                goto on_err;
            }

            read_buffer = tmp;
            read_buffer_size = new_size;
        }
    }

    retval = 0;
    goto on_exit;

on_err:
    free(read_buffer);
    read_buffer = NULL;

on_exit:
    *output = read_buffer;

    return retval;
}

int parse_cmd(char * input_str, char *** out_argv, size_t * out_argc) {
    if(input_str == NULL || out_argv == NULL || out_argc == NULL || (strlen(input_str) == 0)) {
        LOG("parse_cmd: bad input params");
        return -1;
    }

    LOG("parse_cmd %s", input_str);

    *out_argc = 1;
    //Let's calculate how much items with ' ' delimiter we have.
    //For example, if user run in the shell:
    //ls -la -lu -lc
    //We have 4 items.
    size_t input_len = strlen(input_str);
    for(int i = 0; i < input_len; i++) {
        if (input_str[i] == ' ')
            (*out_argc) += 1;
    }

    *out_argv = malloc(((*out_argc) + 1 /*for NULL at the end of argv*/) * sizeof(char*));
    if(*out_argv == NULL) {
        LOG("malloc fail");
        return -1;
    }

    (*out_argv)[*out_argc] = NULL; /*for NULL at the end of argv*/

    char *saveptr;

    if((*out_argc) == 1) {
        (*out_argv)[0] = input_str;
    } else {
        for(int i = 0; i < (*out_argc); i++) {
            if(i == 0) {
                (*out_argv)[i] = strtok_r(input_str,  " ", &saveptr);
            } else {
                (*out_argv)[i] = strtok_r(NULL, " ", &saveptr);
            }
            LOG("detect argv param %s", (*out_argv)[i]);
        }
    }

    return 0;
}
/*
 * This command do fork() and run execv. Then it wait the child and get output from the child.
 * The output is returned in output_ptr
 * We use pipe to get output from the child
 */
int run_cmd(char * const argv[], int argc, char** output_ptr) {
    if(argv == NULL || output_ptr == NULL || argc == 0) {
        LOG("run_cmd: bad input params");
        return -1;
    }

    LOG("run %s", argv[0]);

    for(int i = 0; i < argc; i++) {
        LOG("argv[%d]: %s", i, argv[i]);
    }

    int pipefd[2];
    pid_t cpid;

    if (pipe(pipefd) != 0) {
        LOG("pipe fail: %d", errno);
        return errno;
    }

    cpid = fork();
    if (cpid == -1) {
        LOG("fork fail: %d", errno);
        return errno;
    }

    if (cpid == CHILD_ID) {
        close(pipefd[READ_END]);          /* Close unused read end */

        if(dup2(pipefd[WRITE_END], STDOUT_FILENO) < 0) { // send stdout to the pipe
            return errno;
        }

        if(dup2(pipefd[WRITE_END], STDERR_FILENO) < 0) {  // send stderr to the pipe
            return errno;
        }

        close(pipefd[WRITE_END]);    // this descriptor is no longer needed

        execvp(argv[0], argv);
        LOG("execvp in child was failed: %d", errno);
        exit(EXIT_FAILURE);
    } else {            /* Parent */
        close(pipefd[WRITE_END]);          /* Close unused write end */

        char buffer[4096];
        *output_ptr = NULL;

        //*len_ptr = 0;

        int retval = -1;
        int not_memory = 0;

        size_t byte_write = 0;
        int byte_read = 0;
        while ((byte_read = read(pipefd[READ_END], buffer, sizeof(buffer))) > 0)
        {
            unsigned char* tmp_ptr = realloc(*output_ptr, byte_write + byte_read + 1 /*for '\0'*/);
            if(tmp_ptr == NULL) {
                not_memory = 1;
                LOG("failed to allocate memory");
                break;
            }
            *output_ptr = tmp_ptr;
            memcpy(*output_ptr + byte_write, buffer, byte_read);
            byte_write += byte_read;
        }

        if(byte_read == 0) {
            //*len_ptr = byte_write;

            if(*output_ptr != NULL) {
                (*output_ptr)[byte_write] = '\0'; //see realloc above
            }
        }

        if(byte_read < 0 || not_memory) {
            LOG("read fail: %d", errno);
            free(*output_ptr);
            *output_ptr = NULL;
        }

        close(pipefd[READ_END]);

        int wstatus;
        if (wait(&wstatus) != -1) {
            int wifexited = WIFEXITED(wstatus);
            if(wifexited == 0) {
                LOG("wifexited is zero, wstatus is %d. Child process terminates with error", wstatus);
                retval = wstatus;
            } else {
                int wexitstatus = WEXITSTATUS(wstatus);
                if(wexitstatus != EXIT_SUCCESS) {
                    LOG("wexitstatus: %d not equal to success: %d", wexitstatus, EXIT_SUCCESS);
                }
                retval = wexitstatus;
            }
        } else {
            LOG("wait fail: %d", errno);
            retval = -1;
        }

        return retval;
    }

    return -1;
}