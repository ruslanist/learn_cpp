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
                
		/*
		 * Ниже я задал прототип конструктора копирования. Нужно реализовать его тело в cpp файле.
		 * ПРо конструкторы копирования можно в этих двух статьях получить инфу
		 * http://cppstudio.com/post/9903/
		 * https://ru.wikipedia.org/wiki/%D0%9A%D0%BE%D0%BD%D1%81%D1%82%D1%80%D1%83%D0%BA%D1%82%D0%BE%D1%80_%D0%BA%D0%BE%D0%BF%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F
		 * Плюс, в прате и вдейтле полюбому должна быть инфа о них, надо смотреть по предметному указателю, в конце книги
		 *
		 * Вот пример, когда вызывается этот конструктор.
		 * AString str("Hello1"); //создали первый объект, тут позоветься обычный конструктор
		 * AString str2 = str; //создаем второй объект и инициализируем его первым str. В этот момент будет вызван именно этот копирующий конструктор
		 * В теле этого копирующего конструктора должен быть реализован следующий алгоритм:
		 * 1. str.bufLen должнен быть присвоен в str2.bufLen.
		 * 2. для str2.internBuf через new выделяют память размером str2.bufLen
		 * 3. в str2.internBuf через memcpy копируют из str.internBuf память, длинной str.bufLen
		 *
		 * В теле копирующего конструктора, можно обращаться к приватным полям из other.
		 * Ну т.е.
		 * AString::AString(const AString& other) {
		 * 	//какой-то код
		 * 	bufLen = other.bufLen; // вот эта строчка копирует в bufLen ЭТОГО объекта, bufLen из объекта other. И ему пофиг, что bufLen в привате.
		 * 	//какой-то код
		 * }
		 */
		AString(const AString& other); //Копирующий конструктор.
		
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
