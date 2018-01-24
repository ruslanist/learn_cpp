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


using namespace std;


int main(int argc, char** argv) {

   try {cout << "runtime_error(error)" << endl;
   
   } // Конец Блока try
   
   catch(SnmpError &snmpError) {
       
       cout << "Произошло Исключение - Ошибка: " << snmpError.what() << endl;
       
       
   } // Конец catch
    
    return 0;
}

