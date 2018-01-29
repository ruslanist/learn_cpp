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
#include "NetSnmp.h"

using namespace std;


int main(int argc, char** argv) {

   try {
        //sudo apt-get install snmpd
        //sudo apt-get install snmp
        //sudo /etc/init.d/snmpd start

        //Убедится, что эта команда ниже выведет результаты оидов
        //snmpwalk -v2c -c public 127.0.0.1  .

        NetSnmp netSnmp("127.0.0.1", "public");
        cout << "Количество функций, которое предоставляет это оборудование: " << netSnmp.getInt("1.3.6.1.2.1.1.7.0") << endl;
   
        
        NetSnmp snmpAid("1.3.6.1.2.1.1.1.0", "public");
        cout << "Определение вендора/модели/Имя устройства: " << snmpAid.getString("1.3.6.1.2.1.1.1.0") << endl;
        
        NetSnmp snmpAid("1.3.6.1.4.1.9.10.24.1.1.2.0", "public");
        cout << "Число юзеров активных всего (SessionTotal): " << snmpAid.getString("1.3.6.1.4.1.9.10.24.1.1.2.0") << endl;
        
   } // Конец Блока try
   
   catch(const SnmpError &snmpError) {
       
       cout << "Произошло Исключение - Ошибка: " << snmpError.what() << endl;
          
   } // Конец catch
   
   catch(...) {
   
       cout << "В программе произошла не известная ошибка" << endl;
       
   } //Конец catch2
    
    return 0;
}

