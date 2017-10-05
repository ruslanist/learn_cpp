/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AString.cpp
 * Author: ruslan
 *
 * Created on 5 октября 2017 г., 17:09
 */

#include <cstdlib>
#include<stdexcept>
#include<iostream>
#include<cstring>
using namespace std;

#include "AString.h" // Поидерадключение класа AString


NotImpl::NotImpl(const char* reason) : std::runtime_error(reason) {}

AString::AString(const char* input) {
			bufLen = strlen(input);
			internBuf = new char[bufLen + 1 /*for '\0'*/];
			strcpy(internBuf, input);
		}

AString::~AString() {
	//		delete internBuf;
		}

size_t AString::find_first_of(char ch) const {
			for(size_t i = 0; i < bufLen; i++) {
				if(internBuf[i] == ch)
					return i;
			}
			return npos;
		}

size_t AString::find_last_of(char ch) const {
			throw NotImpl("'find_last_of' not implemented yet");
		} // Конец Функции find_last_of()  

const char* AString::c_str() const {
                    return internBuf;

} // Конец Функции c_str().