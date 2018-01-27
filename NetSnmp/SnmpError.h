/*
 * Создание класса отвечающего за отслежывания и обработки эксепшена
 */

/* 
 * File:   SnmpError.h
 * Author: ruslan
 *
 * Created on 26 января 2018 г., 23:19
 */

#ifndef SNMPERROR_H
#define SNMPERROR_H

#include<stdexcept>
#include<string>

using std::string;
using namespace std;


class SnmpError : public std::runtime_error {
    
    public:
           SnmpError(const string& err);
    
}; // Конец Класc SnmpError



#endif /* SNMPERROR_H */
