/*
 * Данна программа является колькулятором мзчесления велечин таких как:
 *(Литры, Килограммы, метры и.т.д.). Ознокомится со списком всех велечин Вы 
 * можете в  представленном меню ниже.
 */

/* 
 * File:   main.cpp
 * Author: Ruslan Istomin
 *
 * Created on 20 октября 2016 г., 24.00
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * Класс который отвечает за вывод информации еденицах измерениях.
 */

class Information
{
public:
    
    void inf_izmereniya()
    {
        cout << "Меню предаставляющее Информацию о ед. Измерения.\n";
        
        cout << "1) Литры - Это.\n";
        cout << "2) Милилитры - Это.\n";
        cout << "3) Килограммы - Это.\n";
        cout << "4) Тонны - Это.\n";
        cout << "5) Метры - Это.\n";
        cout << "6) Сантиметры - Это.\n";
        cout << "7) Милиметры - Это.\n";
        cout << "8) Метр квадратный - Это.\n";
        cout << "9) Часы - Это.\n";
        cout << "10) Минуты - Это.\n";
    }
};

int main(int argc, char** argv) {
    
    
    int num_menu;
    
    Information.inf_izmereniya();
    
    cout << "Меню - Калькулятор велечин изчисления см., кг., м., мин., др.: \n";
    
    cout << "№1. Расчет Литров в Миллилитры\n";
    cout << "№2. Расчет Килограммов в милиграммы\n";
    cout << "№3. Расче  Тонны в Килограммы\n";
    cout << "№4. Расчет Метры в Сантиметры\n";
    cout << "№5. Расчет Сантиметры в Милиметры\n";
    cout << "№6. Расчет Площади в метрах квадратных\n";
    cout << "№7. Расчет Часы в Минуты\n";
    
    cout << "Введите пожалуйста номер интересующего Вас № пункта от (1 - 7):";
    cin >> num_menu;
    
    
    switch(num_menu) {
    
        case 1:
            double liters, mililitrs;   
            
            cout << "В ведити количество Литров.\n";
            cin >> liters;
            mililitrs = liters * 1000;
            cout << mililitrs << "Милилитров.\n";
            break;
            
         case 2:
            double kilogram, gram;   
                     
            cout << "В ведити количество Килограм.\n";
            cin >> kilogram;
            gram = kilogram * 1000;
            cout << gram << "Грам.\n";
            break;
            
          case 3:
            double tonn, kilogramm;   
            
            cout << "В ведити количество Тонн.\n";
            cin >> tonn;
            kilogramm = tonn * 1000;
            cout << kilogramm << "Килограм.\n";
            break;
            
            case 4:
                double metrs, santimetrs;   
            
            cout << "В ведити размер в Метрах.\n";   
            cin >> metrs;
            santimetrs = metrs * 100;
            cout << santimetrs << "Сантиметров.\n";
            break;
            
            case 5:
                double santimetrss, milimetrs;   
            
            cout << "В ведити размер в Сантиметрах.\n";
            cin >> santimetrss;
            milimetrs = santimetrss * 10;
            cout << milimetrs << "Милиметров.\n";
            break;
            
            case 6:
                double metrsh, metrsd, metrskv;   
            
            cout << "В ведити Ширену в метрах.\n";
            cin >> metrsh;
            
            cout << "В ведити Длину в метрах.\n";
            cin >> metrsd;
            metrskv = metrsh * metrsd;
            cout << "Площадь равна" << metrskv << "Метров квадратных.\n";
            break;
            
            case 7:
                double chasu, minutu;   
            
            cout << "В ведити количество Часов.\n";
            cin >> chasu;
            minutu = chasu * 60;
            cout << minutu << "Минут.\n";
            break;
            
            default:
                cout << "Вы должны ввести число от 1 до 6.endl";
    }
    
    

    return 0;
}