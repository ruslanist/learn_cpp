/*
 * main Файл.
 */

/*
 * File:   main.cpp
 * Author: ruslan
 *
 * Created on 4 декабря 2017 г., 2:03
 */

#include <cstdlib>
#include<iostream>
#include"SnmpError.h"


using namespace std;


int main(int argc, char** argv) {

   try {cout << "runtime_error(error)" << endl;
   
   } // Конец Блока try
   
   catch(const SnmpError &snmpError) {
       
       cout << "Произошло Исключение - Ошибка: " << snmpError.what() << endl;
          
   } // Конец catch
   
   catch(...) {
   
       cout << "В программе произошла не известная ошибка" << endl;
       
   } //Конец catch2
    
    return 0;
}

