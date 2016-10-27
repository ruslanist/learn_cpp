/*
 * Урок №2 Home Work Калькулятор Градус  в Фарингейт и Курсы валюты
 */

/* 
 * File:   main.cpp
 * Author: ruslan
 * Created on 26 октября 2016 г., 0:51
 */

#include <cstdlib>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char** argv) {
cout << "Вас преветствует калькулятор Валюты и градусов по фарингейту" << endl;
cout << "Ниже представленно меню, где можно выбрать нужный Вам пункт" << endl;

cout << "Меню Программы" << endl;

int num_menu;

    cout << "№1. Конвертация  Курса USD к Рублю на 26.10.2016" << endl;
    cout << "№2. Конвертацият Курса EURO к Рублю на 26.10.2016" << endl;
    cout << "№3. Перевод Градусов целсия в Форингейт" << endl;
  
     
    for(; true ;)
    {
    cout << "Введите пожалуйста номер интересующего Вас № пункта от (1 - 3):";
    cin >> num_menu;
    
    
    switch(num_menu) {
    
        case 1: 
            double usd, rub1;   
            
            cout << "В ведити Сумму USD.\n";
            cin >> usd;
            rub1 = usd * 63.82;
            cout << rub1 << "Рублей." << endl;
            break;
            
         case 2:
            double euro, rub2;   
                     
            cout << "В ведити Сумму EURO"   << endl;
            cin >> euro;
            rub2 = euro * 78.64;
            cout << rub2 << "Рублей" << endl;
            break;
            
          case 3:
             
            double c, f, a;
            int b;
            b = 32;
            a = 1.8;
                    
            cout << "В веди температуру градусов цельсия." << endl;
            
            cin >> c;
            f = (c * a) + b ;
            cout << f << "Температура градусов по Фаренгейту" << endl;
            
            break;
           
            
            default:
                cout << "Вы должны ввести число от 1 до 6.endl";
        }
    
    }
    

    return 0;
}

