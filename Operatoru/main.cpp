/*
 * The file of main.cpp 
 */

/* 
 * File:   main.cpp
 * Author: ruslan
 *
 * Created on 29 января 2018 г., 14:32
 */


#include "OperatorsBase.h"
#include "OperatorsPointers.h"
#include"OperatorsLink.h"
#include"OperatorsInformation.h"


#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;


int main(int argc, char** argv) {
    
    int menu;
    
       OperatorsPointers pointObj;
       OperatorsLink linkObj;    
       OperatorsInformation infoObj;
      
      for(; true ;)
      {
       cout << "Меню программы" << endl;
       
        cout << "Данная программа позволит Ввести и сохронить OId и его " 
                << "идентификатор, а также вывести значения на экран"<< endl;
        
        cout << "Замечание: Для корректной работы программы " 
                "Заполните прежде в меню, пункты 1 2, 3 " << endl;
       
    cout << "1) Введите два OID с Идентификаторы и краткое описания введенного OID" << endl;
            cout << "Кратко свою информацию об  OID и MIB, а также информацию о сервере и свичемкоторый Вы используете (цифра 1)" << endl;
    cout << "2) Ввести и вывести на экран OID и Идентификатор (цифра 2)" << endl;
    cout << "3) Ввести и вывести на экран 2(два) OID и Идентификаторы, а а также вывести их значения на экран (цифра 3)" << endl;
    cout << "4) Вывести Информацию полей хранащию инфу введеную Вами о OID и MIB (цифра 4) " << endl;
    cout << "5) Вывести введенную Вами информацию об используемом Свиче и Сервере (цифра 5)" << endl;
    cout << "6) Вывести сохраненный в поля OID1  (цифра 6) " << endl;      
    cout << "7) Вывести сохраненный в поля OID2  (цифра 7) " << endl;
    cout << "8) Вывести все сохраненный в поля OID-ы (цифра 8)" << endl;      
    cout << "9) Вывести общию информацию об протоколе Net-Snmp (цифра 9)" << endl;
    cout << "10)Вывести различные расчеты используя ссылки и указатели (цифра 10)" << endl;
    cout << "11)Вывести общию информацию об OID и MIB  (цифра 11)" << endl;
    cout << "12)Для Выхода из программы выберите этот пункт менб и нажмите 0  (цифра 12)" << endl;
    
    cin >> menu;
                 
    switch(menu)
    {
    
        case 1:
        {
        
            
                                                                                                    
             string aid1;
             string nameAid1;
             string descAid1;
             string aid2;
             string nameAid2;
             string descAid2;
             string infAid;
             string infMib;
             string svitchname;
          
             string svitchIP;
             string svitchOS;
             string servername;
             string serverIP;
             string serverOS;
            
            cout << "Введите  OID и Идентификатор, в следующем порядке: 1-й OID, Идентификатори, описание OID" 
                    << " 2-й OID, Идентификатори, описание OID" << endl;
            
            cout << "Введите первый OID" << endl;
            cin >> aid1;
            
            cout << "Введите Индефикатор для первого OID" << endl;
            cin >> nameAid1;
            
            cout << "Введите краткое описание к первому OID" << endl;
            cin >> descAid1;
            
            cout << "Введите второй OID" << endl;
            cin >> aid2;
            
            cout << "Введите Индефикатор для второго OID" << endl;
            cin >> nameAid2;
            
            cout << "Введите краткое описание к второму OID" << endl;
            cin >> descAid2;
            
            
            
            cout << "Теперь введите пожалуйста информацию касающиюся " 
                    << "Терминалогии и полезной информации об OID и MIB, " 
                      << "а также можете оставить свою информацию для улучшения кода " 
                        << "так нам это поможет всегда улучшить наше приложение для Вас" << endl;
            
            cout << "Введите информацию про OID" << endl;
            cin >> infAid;
            
            cout << "Введите информацию про MIB" << endl;
            cin >> infMib;
            
            
            
         cout << "Здесь Вам нужно ввести информацию о Вашем Свиче и Сервере " << endl;   
            
            cout << "Введите  модель Вашего Свича" << endl;
            cin >> svitchname;
            
            cout << "Введите IP адрес Вашего Свича" << endl;
            cin >> svitchIP;
            
            cout << "Введите версию ПО Вашего Свича" << endl;
            cin >> svitchOS;
            
            cout << "Введите  модель Вашего Сервера" << endl;
            cin >> servername;
            
            cout << "Введите IP адрес Вашего Сервера" << endl;
            cin >> serverIP;
            
            cout << "Введите версию ПО Вашего Сервера" << endl;
            cin >> serverOS;
            
            
            
            pointObj.setoperatorAid1(aid1);
            pointObj.setoperatorName1(nameAid1);
            pointObj.setoperatordescAid1(descAid1);
            pointObj.setoperatorAid2(aid2);
            pointObj.setoperatorName2(nameAid2);
            pointObj.setoperatordescAid2(descAid2);
            
            pointObj.setoperatorinfAid(infAid);
            pointObj.setoperatorinfMib(infMib);
            
            pointObj.setswitchName(svitchname);
            pointObj.setswitchIP(svitchIP);
            pointObj.setswitchOS(svitchOS);
            pointObj.setserverName(servername);
            pointObj.setserverIP(serverIP);
            pointObj.setserverOS(serverOS);
                
        }
            break;
       
                                    
        case 2:
        {
            
            string aid1;
            string nameAid1;
           
            
           cout << "Введите  OID" << endl;
           cin >> aid1;
            
           cout << "Введите Индефикатор для введенного OID" << endl;
           cin >> nameAid1;
           
           linkObj.operatoraidName(aid1, nameAid1);
            
        }    
            break; 
        
        
        case 3:
        {
            
            string aid1;
            string nameAid1;
            string aid2;
            string nameAid2;
            
            cout << "Введите первый OID" << endl;
            cin >> aid1;
            
            cout << "Введите Индефикатор для первого OID" << endl;
            cin >> nameAid1;
            
           
            
            cout << "Введите второй OID" << endl;
            cin >> aid2;
            
            cout << "Введите Индефикатор для второго OID" << endl;
            cin >> nameAid2;
            
            linkObj.operatoraidNameAll(aid1, nameAid1, aid2, nameAid2);
          
        }                           
              break; 
              
        case 4:
            
        {
            cout << "Термины и Ваше дополнение об OID: "<< pointObj.getoperatorinfAid() << endl;
            
            cout << "Термины и Ваше дополнение об MIB: " << pointObj.getoperatorinfMib() << endl;
        }
              break;        
              
        case 5:
        {
            cout << "Используемый Вами Свич:" << endl;
            
            cout << " Модель Свича: " << pointObj.getswitchName() << endl;
                cout << "IP адрес Свича: " << pointObj.getswitchIP() << endl;
                    cout << "Свича: " << pointObj.getswitchOS() << endl;
                    
            cout << "Используемый Вами Сервер:" << endl;
            
            cout << " Модель Сервера: " << pointObj.getserverName() << endl;
                cout << "IP адрес Сервера: " << pointObj.getserverIP() << endl;
                    cout << "Сервера: " << pointObj.getserverOS() << endl;
            
        }
        
              break;    
                      
        case 6:
        {
            cout << "OID1 :" << pointObj.getoperatorAid1() << " " 
                    << pointObj.getoperatorName1() << " " 
                      << pointObj.getoperatordescAid1() << endl;
        }
            break; 
            
       case 7:
        {
            cout << "OID2 :" << pointObj.getoperatorAid2() << " " 
                    << pointObj.getoperatorName2() << " " 
                      << pointObj.getoperatordescAid2() << endl;
        }
            break; 
                     
        case 8:
        {
            cout << "OID1 :" << pointObj.getoperatorAid1() << " " 
                    << pointObj.getoperatorName1() << " " 
                      << pointObj.getoperatordescAid1() << endl;
            
            cout << "OID2 :" << pointObj.getoperatorAid2() << " " 
                    << pointObj.getoperatorName2() << " " 
                      << pointObj.getoperatordescAid2() << endl;
            
        }
            break; 
         
        case 9:
        {
            pointObj.aidInform();
               
        }
            break; 
            
        case 10:
        {
           linkObj.aidInform();
            
        }
            break;
            
        case 11:
        {
            infoObj.aidInform();
            
        }
            break;
            
        case 12:
       {
           int a = 0;
           cin >> a;
            
        }
            break;
             
    } // Конец цикла Switch
    
      } // Конец циклаfor
    

    return 0;
    
}