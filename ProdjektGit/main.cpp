/* Начала работы в GitHub
 * 
 */


#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

/* 
* Создание Класса GrandBook
*/

class GitHub 
{ 
public:
    // Метод выводящий приветствия
    void displayMessage() {
    cout << "Добро пожаловать GitHub!" << endl;
    }
    
    void displayMessage2() {
        cout << "Hello!" << endl;
    }
    
    void git_match()
    {
        // Объявление переменных
     int sum1=154, sum2=234, sum3=367, sum4=576, sum5=754, sum6=635;
        
        // Вычисление  переменных sum1, 2, 3. 4. 5. 6
        int a= sum1 + sum4;
        int b= sum2 * sum3;
        int c= sum5 - sum6;
        
        // Вычисление Итоговой Суммы переменных a, b и c
        int itogo= a+b+c;
        
        // Отоброжения равенства a, b, c
        cout << a << b << c << endl; 
        
        // Отображение итоговой суммы переменных a, b и c
        cout << itogo << endl;
    }
    
    // Обьявление Конструктора GitHub
    GitHub() 
    {
        int consruct1=25, construct2=50, construct3=75, construct4=100;
        
        int itog_constr;
        
        
        itog_constr = construct2 + construct4;
        
        cout << itog_constr << endl;
    }
        
}; // Конец Класса GitHub

/*
 * Функция main реализующая класс GitHub
 */
int main(int argc, char** argv) {
    
    GitHub myGitHub; // Создание GitHub с именем  myGithub;
    
    myGitHub.displayMessage(); // Вызов метода displayMessage() класса GitHub
    
    myGitHub.displayMessage2(); // Вызов метода displayMessage2() класса GitHub

    myGitHub.git_match(); // Вызов метода git_match() класса GitHub

    return 0;
}

