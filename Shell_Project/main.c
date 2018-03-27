#include <utils.h>

int main(int argc, char * argv[]) {
    
#ifdef NEED_LOG
    fprintf(stdout, "LOG_ENABLED\n");  
#endif

    while(1) {
        fprintf(stdout, "#");
    
        char * input_buf = NULL;
        char * cmd_output = NULL;
        char * argv = NULL;
        size_t ** argc = 0;
    
        //This function read user's input from stdin until user press Enter('\n')
        if(read_stream(stdin, &input_buf) !=0) {
            fprintf(stderr, "read_stream fail");
            return -1;
        }
    
        //Here are we check, if input_buf is empty(strlen == 0) or not.
        //If user simply run Enter. input_buf will be empty.
        if(strlen(input_buf) > 0) {
        //So, we have some input from user, let's try to parse it as a command, like 'ls -la', or 'pwd'
            if(parse_cmd(input_buf, &argv, &argc) != 0) {
                fprintf(stderr, "parse_cmd fail");
                return -1;
            }
            /*
             * If we parse successfully, 'argv' will contain the array of pointers to a programm and it args, for example
             * ~#  ls -la
             * argv[0] == ls
             * argv[1] == -la
             *
             * argc - is simply a number of items in argv
             * Now, we need to run ls
             */
            run_cmd(argv, argc, &cmd_output);

            /*
             * cmd_output contains output from launched command.
             * For example, if you run in the shell: 'ls'
             * cmd_output will contain a list of files and folders in the current directory.
             * Another example -if you run in the shell: 'pwd'
             * cmd_output will contain the path to the current directory, like '/home/user/shell_project/'
             * But if you run a programm in the shell and  it doesn't produce any output, cmd_output will be empty or null
             */
            fprintf(stdout, "%s\n", cmd_output == NULL ? "" : cmd_output);

            free(cmd_output);
            free(argv);

            //Here we end one iteration. In the next iteration, we will print prompt ~# again.
        }

        free(input_buf);
    
    
    }

}