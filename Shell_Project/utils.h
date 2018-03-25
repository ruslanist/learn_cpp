

/* 
 * File:   utils.h
 * Author: ruslan
 *
 * Created on 22 марта 2018 г., 9:43
 */

#ifndef UTILS_H
#define UTILS_H

#include<stdio.h>
#include<string.h>

#ifdef NEED_LOG
#define LOG_ENABLED 1
#else
#define LOG_ENABLED 0
#endif






int run_cmd(char * const argv[], int argc, char** output_ptr);
int read_stream(FILE * f, char ** output);
int parse_cmd(char *input_str, char ***out_argv, size_t * out_argc);
