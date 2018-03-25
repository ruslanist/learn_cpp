

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