/*
 Заголовочный Файл обявляющий Класс и конструкторы  NotImp,  AString, Диструктор
 *  AString, приват Поля.
 * Функции find_first_of(), find_last_of(), c_str().
 */

/* 
 * File:   AString.h
 * Author: ruslan
 *
 * Created on 5 октября 2017 г., 3:16
 */

#ifndef ASTRING_H
#define ASTRING_H



#endif /* ASTRING_H */

#include<stdexcept>
#include<iostream>
#include<cstring>

class NotImpl : public std::runtime_error {
	public:
		NotImpl(const char* reason);
};



// Определение Класса AString
class AString {
	public:
		const static size_t npos = -1;
                
		AString(const char* input); // Конструктор
		~AString(); // Диструктор
                
		size_t find_first_of(char ch) const; // Функция
                
		size_t find_last_of(char ch) const; // Функция
                
		const char* c_str() const; // Функция
                
	private:
		char * internBuf;
		size_t bufLen;

}; // Конец Класса 
