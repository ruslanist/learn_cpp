

/* 
 * File:   utils.h
 * Author: ruslan
 *
 * Created on 22 марта 2018 г., 9:43
 */

#ifndef UTILS_H
#define UTILS_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>

#ifdef NEED_LOG
#define LOG_ENABLED 1
#else
#define LOG_ENABLED 0
#endif

#define LOG(fmt, ...) do {if(LOG_ENABLED) fprintf(stderr, "%s[%d]: " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__);} while(0)






int run_cmd(char * const argv[], int argc, char** output_ptr);
int read_stream(FILE * f, char ** output);
int parse_cmd(char *input_str, char ***out_argv, size_t * out_argc);
