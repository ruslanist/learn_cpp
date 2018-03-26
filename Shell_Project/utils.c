
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

       
 on_err:       
        
       
        
   }
    
    
   
    
    
    
    
    
    
    
    
 }


int run_cmd(char * const argv[], int argc, char** output_ptr) {
    

    }


int parse_cmd(char *input_str, char ***out_argv, size_t * out_argc) {


    }