/*
 * Файл содержащий реализацию программы
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
#include<memory>

using namespace std;

#include "AString.h" // Поидерадключение класа AString


NotImpl::NotImpl(const char* reason) : std::runtime_error(reason) {}

// Ниже представлена Реализация Копирующего Конструктора.
AString::AString(const AString& other) {
    
                        bufLen = other.bufLen;                                         
                        internBuf.reset(new char[bufLen + 1]);
                        memcpy(internBuf.get(), other.internBuf.get(), bufLen);
                        
                }

// Оператор Определения Копирования
AString& AString::operator=(const AString& other) {

                        bufLen = other.bufLen;                                         
                        internBuf.reset(new char[bufLen + 1]);
                        memcpy(internBuf.get(), other.internBuf.get(), bufLen);
                        return *this;
                }

AString::AString(const char* input) {
			bufLen = strlen(input);
			internBuf.reset(new char[bufLen + 1 /*for '\0'*/]);
			strcpy(internBuf.get(), input);
		}

AString::AString(const char* input, size_t len) {

                    internBuf.reset(new char[len+1]); // (+1) Это для выделения доп места под (\0)
                    bufLen = len+1; // (+1) Это для выделения доп места под (\0)
                    memcpy( internBuf.get(), input, len); 
                    internBuf[len] = '\0'; // Задаем (\0).
                }	      		

size_t AString::find_first_not_of(char ch) const {

    for(size_t i = 0; i < bufLen; i++) {
                        
        if(internBuf[i] != ch)
            return i;
    }
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
    return internBuf.get();
} // Конец Функции c_str().

AString& AString::append(const char* input) {

   size_t inputLen = strlen(input); 
   std::unique_ptr<char[]> p(new char[inputLen+bufLen+1]);
   memcpy(p.get(), internBuf.get(), bufLen);
   memcpy(p.get()+bufLen, input, inputLen);
   p[inputLen+bufLen] = '\0';
   internBuf = std::move(p); 
   bufLen = inputLen+bufLen;
   
        return *this;
}


AString& AString::prepend(const char* input) {

    size_t inputLen_2 = strlen(input);
    std::unique_ptr<char[]> p2(new char[inputLen_2+bufLen+1]);
    memcpy(p2.get(), input, inputLen_2);
    memcpy(p2.get()+inputLen_2, internBuf.get(), bufLen);
    p2[inputLen_2+bufLen] = '\0';
    internBuf = std::move(p2);
    bufLen = inputLen_2+bufLen;
        
        return *this;
} 
