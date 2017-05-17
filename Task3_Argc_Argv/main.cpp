/*
 * Задача 3: Программа принемает argv аргументы, далее присваевает их  
 * переменной с типом string, далее полученые аргументы собирает в одну строку и 
 * все прописные буквы выводит в верхний регистр.
 */

/* 
 * File:   main.cpp
 * Author: ruslan
 *
 * Created on 13 мая 2017 г., 19:01
 */

#include <cstdlib>

#include <cctype>

#include <iostream> 
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;


int main(int argc, char** argv) {
    
    int num_menu;
    
    string str;
    
    cout << "Меню - Программа вывода аргументов (argv[i])" << endl;
    
    cout << "№1. Вывод всех введенных аргументов в одну строку" 
            << "и преведение символов в верхний регистр" << endl;
    cout << "№2. Вывод всех введенных аргументов в одну строку" << endl;
    cout << "№3. Осуществление поиса и ввода целого числа в argv[i]" 
            << "Если программа находит в argv[i] число то оно выведит его н"
              << "Если нет целого числа, то выводит (0)" << endl; 
    cout << "№3. Выход из программы" << endl;
       

    for(; true ;)
    {
        cout << "Введите пожалуйста номер интересующего Вас № пункта от (1-4):";
        cin >> num_menu;
    
        switch(num_menu) 
        {
            case 1:
                
               cout << "Соеденение входных параметров в одну строку и" << " "
                      << "приведение всех символов в верхний регистр" << endl;
                
                
                for(int i=0; i<argc; i++)
                   {
        
                     str += argv[i];  
        
                   }
    
                for(int i=0; i<str.size(); i++)
                   {
    
                    str[i] = toupper(str[i]);
    
                   }
                        
                        cout << str << endl;
            
                break;
            
            case 2:
             
                cout << "Соеденение входных параметров в одну строку" << endl;
                
                for(int i=0; i<argc; i++)
                   {
        
                     str += argv[i];  
        
                   }
            
                        cout << str << endl;                       
                break;
                          
            
            
             case 3:
             
                cout << "Поиск целых чисел в веденых Вами аргументах" << endl;
                
                for(int i=0; i<argc; i++)
                   {
                    
                    int Num = 0;
	 
		    if(Num = atoi(argv[i]))

			{ 
                     
                    	 cout << Num << endl;

        		} else 

				{
				 cout << "Данный аргумент введен не коректно" << argv[i] <<  endl;
				}
                   }
                
                                            
                   break;  
                
                
               case 4:
             
                       cout << "Выход из программы" << endl;
                
                       exit(1);
                
                                            
                   break;

      
                       default:
                            cout << "Вы должны ввести число от 1 до 4" << endl;
        
    }   
    
   
}
    
 return 0;

}



