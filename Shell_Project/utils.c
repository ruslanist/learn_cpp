
#include<utils.h>

#include<stdio.h>
#include<string.h>

/* 
 * File:   utils.c
 * Author: ruslan
 *
 * Created on 22 марта 2018 г., 10:11
 */

int read_stream(FILE * f, char ** output) {
    int retval = -1;
    char * read_buffer = NULL;
    size_t * read_buffer_size = 1024;
    
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
        //We must break the client input, because the user presses Enter. This means the end of the team. We do not need to read more from the user.
       
        if(ch == '\n') {
        read_buffer[read_pos] = '0'; //We end our buffer with user command with null terminator. Because each c-string must ends with null terminator
        //After this, we will be able to safe put read_buffer as argument to printf and other c-string functions.
            break;        
        }
        
        read_buffer[read_pos] = ch;
        
        //if it a last iteration, and we need a more space, we realloc read_buffer
       
        if((read_pos+ 1) == read_buffer_size) {
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
    read_buffer = NULL
    
 on_exit:
    *output  = read_buffer;
    
    return retval;
        
 }


int run_cmd(char * const argv[], int argc, char** output_ptr) {
    

    }


int parse_cmd(char *input_str, char ***out_argv, size_t * out_argc) {


    }