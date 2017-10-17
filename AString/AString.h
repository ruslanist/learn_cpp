/*
 * Заголовочный файл содержащий интерфейс программы, совокупность классов и
 * методов приложения
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

		//Сделать реализацию для этого конструктора.
		//Суть его работы в том, что он должен взять не всю строчку из input и сохранить в себя,
		//а только len символов из input сохранить в себя
		//Существует функция стандартной библиотеки, она называется memcpy, вот о ней статья
		//http://cppstudio.com/post/678/
		//ее нужно использовать, что бы скопировать заданную часть строки в свой внутренний буфер
		AString(const char* input, size_t len);

		~AString(); // Диструктор
                
		//Реализовать эту функцию.
		//Суть ее работы в том, что она возвращает индекс первого символа, не равного ch
		//Например если есть строка "......word...."
		//и на нее зовут find_first_not_of(.)  - т.е. искать первый символ, не равный точке
		//то она вернет 6 индекс, на 6 индексе находится буква w
		size_t find_first_not_of(char ch) const; // A               

		size_t find_first_of(char ch) const; // Функция
                
		size_t find_last_of(char ch) const; // Функция
                
		const char* c_str() const; // Функция
                
                AString& append(const char* input); // Прототип метода для обеденения строк

		//Реализовать функцию prepend.
		//Она добавляет строку из input в начало той строки, что хранится в объекте AString.
		//Например:
		//AString str("Hello");
		//str.prepend("My Friend);
		//std::cout << str.c_str() << std::endl;
		//cout строчкой выше должен вывести: "My Friend Hello"
		AString& prepend(const char* input);
	private: 
		char * internBuf;
		size_t bufLen;

}; // Конец Класса 