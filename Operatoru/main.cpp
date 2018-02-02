/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ruslan
 *
 * Created on 29 января 2018 г., 14:32
 */


#include "OperatorsBase.h"
#include "OperatorsPointers.h"
#include "OperatorsLink.h"
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
       
    cout << "1) Введите и сохроните введенные 2-а Оида и Идетифекаторы к ним, " 
            << "В такой последовательности: Оид, Идентифекатор, Оид Идентификатор (цифра 1)" << endl;
    cout << "2) Ввести и вывести на экран OID и Идентификатор (цифра 2)" << endl;
    cout << "3) Ввести и вывести на экран 2-а OID и Идентификаторы, а а также вывести их значения на экран (цифра 3)" << endl;
    cout << "4) Вывести Целое число и Дробное и получить Сумму этих чисел (цифра 4) " << endl;
    cout << "5) Ввести целое число и Дробное и получить Разницу этих чисел (цифра 5)" << endl;
    cout << "6) Ввести сохраненный в поля OID1  (цифра 6) " << endl;      
    cout << "7) Ввести сохраненный в поля OID2  (цифра 7) " << endl;
    cout << "8) Вывести все сохраненный в поля OID-ы (цифра 8)" << endl;      
    cout << "9) Обща терменология по OID и MIB (цифра 9)" << endl;
    cout << "10) Ввывести введенную и сохранненую в полях информацию об OID и MIB (цифра 10)" << endl;
    cout << "11) Получить полную информацию   OID и MIB (цифра 11)" << endl;
    
    cin >> menu;
                 
    switch(menu)
    {
    
        case 1:
        {
        
            
                                                                                                    
            const string &aid1;
            const string &nameAid1;
            const string &descAid1;
            const string &aid2;
            const string &nameAid2;
            const string &descAid2;
            
            cout << "Введите  OID и Идентификатор, в следующем порядке: 1-й OID, Идентификатори, описание OID" 
                    << " 2-й OID, Идентификатори, описание OID" << endl;
            
            cout << "Введите первый OID" << endl;
            cin >> &aid1;
            
            cout << "Введите Индефикатор для первого OID" << endl;
            cin >> &nameAid1;
            
            cout << "Введите краткое описание к первому OID" << endl;
            cin >> &descAid1;
            
            cout << "Введите второй OID" << endl;
            cin >> &aid2;
            
            cout << "Введите Индефикатор для второго OID" << endl;
            cin >> &nameAid2;
            
            cout << "Введите краткое описание к второму OID" << endl;
            cin >> &descAid2;
            
            
            pointObj.setoperatorAid1(&aid1);
            pointObj.setoperatorName1(&nameAid1);
            pointObj.setoperatordescAid1(&descAid1);
            pointObj.setoperatorAid2(&aid2);
            pointObj.setoperatorName2(&nameAid2);
            pointObj.setoperatordescAid2(&descAid2);
                
        }
            break;
       
                                    
        case 2:
        {
            
            const string &aid1;
            const string &nameAid1;
           
            
           cout << "Введите  OID" << endl;
           cin >> &aid1;
            
           cout << "Введите Индефикатор для введенного OID" << endl;
           cin >> &nameAid1;
           
           linkObj.operatoraidName(&aid1, &nameAid1);
            
        }    
            break; 
        
        
        case 3:
        {
            
            const string &aid1;
            const string &nameAid1;
            const string &aid2;
            const string &nameAid2;
            
            cout << "Введите первый OID" << endl;
            cin >> &aid1;
            
            cout << "Введите Индефикатор для первого OID" << endl;
            cin >> &nameAid1;
            
           
            
            cout << "Введите второй OID" << endl;
            cin >> &aid2;
            
            cout << "Введите Индефикатор для второго OID" << endl;
            cin >> &nameAid2;
            
            linkObj.operatoraidNameAll(&aid1, &nameAid1, &aid2, &nameAid2);
          
        }                           
              break; 
              
        case 4:
            
        {
             const int& parmAid1; 
             const double& parmAid2;
           
            
           cout << "Введите  челое число" << endl;
           cin >> &parmAid1;
            
           cout << "Введите Дробное число" << endl;
           cin >> &parmAid2;
           
           pointObj.workAid(parmAid1, &parmAid2);
        }
              break;        
              
        case 5:
        {
               const int& parmAid1; 
             const double& parmAid2;
           
            
           cout << "Введите  челое число" << endl;
           cin >> &parmAid1;
            
           cout << "Введите Дробное число" << endl;
           cin >> &parmAid2;
           
           linkObj.workAid(parmAid1, &parmAid2);
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
            
            const string &aidInform;
            const string &mibInform;
            
          cout << "Введи свою информацию об  OID, для пополнения информационной базы" << endl;
            cin >> &aidInform;
            
            cout << "Введи свою информацию об  MIB, для пополнения информационной базы" << endl;
            cin >> &mibInform; 
            
            infoObj.setoperatorinfAid(&aidInform);
            infoObj.setoperatorinfMib(&mibInform);
        }
            break; 
            
        case 10:
        {
           cout << "Что Вы написали об OID1 :" << infoObj.getoperatorinfAid() << endl; 

            cout << "Что Вы написали об MIB :" << infoObj.getoperatorinfMib() << endl; 
            
        }
            break;
            
        case 11:
        {
            infoObj.aidInform();
            
        }
            break;
       
             
    } // Конец цикла Switch
    
      } // Конец циклаfor
    

    return 0;
    
}