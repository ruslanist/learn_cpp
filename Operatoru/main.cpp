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

#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;


int main(int argc, char** argv) {
    
    int menu;
    
       OperatorsPointers aidObj;
       OperatorsLink allAid;     
      
      for(; true ;)
      {
       cout << "Меню программы" << endl;
       
        cout << "Данная программа позволит Ввести и сохронить OId и его " 
                << "идентификатор, а также вывести значения на экран"<< endl;
        
        cout << "Замечание: Для корректной работы программы " 
                "Заполните прежде в меню, пункты 1 2, 3 " << endl;
       
    cout << "1) Введите OID: OID, Идентификатор, OID, Идентификатор " << endl;
    cout << "2) Введите целое число " << endl;
    cout << "3) Введите дробное число" << endl;
    cout << "4) Вывести 1-й OID и Идентификатор цифра 4 " << endl;
    cout << "5) Ввести 1-й OID и Идентификатор цифра 5" << endl;
    cout << "6) Ввести челое число цифра 6 " << endl;      
    cout << "7) Вывести дробное число  цифра 7 " << endl;
   // cout << "8) Вывести информацию о З\П сотрудника за n мес. цифра 8" << endl;      
   // cout << "9) Вывести инф. о З\П с учетом + 10% за n мес., цифра 9" << endl;
   // cout << "Введите интереcующий Вас пункт меню 1  до  9" << endl;
    
    cin >> menu;
                 
    switch(menu)
    {
    
        case 1:
        {
        
            std::unique_ptr<char[]> aidEnter1;
            size_t aidSize1;                                         
            aidEnter1.reset(new char [aidSize1 + 1]);
            
           std::unique_ptr<char[]> nameEnter1;
           size_t nameSize1;                                         
           aidEnter1.reset(new char [nameSize1 + 1]);
            
           std::unique_ptr<char[]> aidEnter2;
           size_t aidSize2;                                         
           aidEnter2.reset(new char [aidSize2 + 1]);
            
           std::unique_ptr<char[]> nameEnter2;
           size_t nameSize2;                                         
           aidEnter2.reset(new char [nameSize2 + 1]);
                                                                                                    
          /*string name1;
            string name2;
            string name1;
            string name2;*/
            
            cout << "Введите  OID и Идентификатор, в следующем порядке: 1-й OID, Идентификатори" 
                    << " 2-й OID, Идентификатори" << endl;
            
            cin.get(aidEnter1, aidSize1).get(nameEnter1, nameSize1).get();
            cin.get(aidEnter2, aidSize2).get(nameEnter2, nameSize2).get();
          
        
            aidObj(aidEnter1, nameEnter1, aidEnter2, nameEnter2);
           
        }
            break;
       
                                    
        case 2:
        {
            string sername1;
            string sername2;
            
            cout << "Введите Фамилию первого сотрудника" << endl;
            cin >> sername1;
            
            cout << "Введите Фамилию второго сотрудника" << endl;
            cin >> sername2;
        
            employeejob1.setEmploySername(sername1);
            employeejob2.setEmploySername(sername2);
        }    
            break; 
        
        
        case 3:
        {
             int salary1;
             int salary2;
            
            cout << "Введите Зарплату первого сотрудника" << endl; 
            cin >> salary1;
            
            cout << "Введите Запрплату второго сотрудника" << endl;
            cin >> salary2;
        
            employeejob1.setEmploySalary(salary1);
            employeejob2.setEmploySalary(salary2);
        }                           
              break; 
              
        case 4:
            
        {
            cout << "Информация о сотруднике №2 (Имя, Фамилия, З/П)" << endl;
            cout << "Имя Сотрудника " << employeejob1.getEmployName() << endl; 
             cout << "Фамилия сотрудника " << employeejob1.getEmploySername() 
                     << endl;
             cout << "Зарплата Сотрудника " << employeejob1.getEmploySalary()
                     << endl;   
        }
              break;        
              
        case 5:
        {
              cout << "Информация о сотруднике №2 (Имя, Фамилия, З/П)" << endl;
              cout << "Имя Сотрудника " << employeejob2.getEmployName() << endl;  
              cout << "Фамилия сотрудника " << employeejob2.getEmploySername() 
                      << endl;
              cout << "Зарплата Сотрудника " << employeejob2.getEmploySalary() 
                      << endl;
        }
        
              break;    
                      
        case 6:
        {
            int salaryresult1;
            int salaryresult2;
            
            cout << "Введите количество месяцев для вычесления" 
                    << "З\П за интересующий Вас период первого сотрудника" 
                      << endl;
            cin >> salaryresult1;
            
            cout << "Введите количество месяцев для вычесления" 
                    << "З\П за интересующий Вас период второго сотрудника" 
                      << endl;
            cin >> salaryresult2;
            
            employeejob1.setEmploySalaryResult(salaryresult1);
            employeejob2.setEmploySalaryResult(salaryresult2);
        }
            break; 
            
       case 7:
        {
            double day1;
            double day2;
            
            cout << "Введите количество месяцев для вычесления" 
                    << "повышения З\П за интересующий Вас период первого" 
                    << "сотрудника" << endl;
            cin >> day1;
            
            cout << "Введите количество месяцев для вычесления" 
                    << "повышение З\П за интересующий Вас период второго" 
                    << "сотрудника" << endl;
            cin >> day2;
            
            employeejob1.setEmployIncrease(day1);
            employeejob2.setEmployIncrease(day2);
        }
            break; 
                     
        /*case 8:
        {
            cout << "Информация о сотруднике №1 (Повышение З\П и расчет за год)" 
                    << endl;
            cout << "Имя Сотрудника " << employeejob1.getEmployName() << endl; 
            cout << "Фамилия сотрудника " << employeejob1.getEmploySername() 
                    << endl;
            cout << "Расчет З\П за год " << employeejob1.getEmploySalaryResult() 
                    << endl; 
            cout << "Расчет повышение З\П " << employeejob1.getEmployIncrease() 
                    << endl;
        }
            break; 
         
        case 9:
        {
            cout << "Информация о сотруднике №2 (Повышение З\П и расчет за год)"
                    << endl;
            cout << "Имя Сотрудника " << employeejob2.getEmployName() << endl; 
            cout << "Фамилия сотрудника " << employeejob2.getEmploySername() 
                    << endl;
            cout << "Расчет З\П за год " << employeejob2.getEmploySalaryResult()
                    << endl; 
            cout << "Расчет повышение З\П " << employeejob2.getEmployIncrease() 
                    << endl;
            
        }
            break; */
       
             
    } // Конец цикла Switch
    
      } // Конец циклаfor
    

    return 0;
    
}