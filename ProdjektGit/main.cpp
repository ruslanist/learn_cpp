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
    cout << "Добро пожаловать GitHub2!" << endl;
    }
        
}; // Конец Класса GitHub

/*
 * Функция main реализующая класс GitHub
 */
int main(int argc, char** argv) {
    
    GitHub myGitHub; // Создание GitHub с именем  myGithub;
    
    myGitHub.displayMessage(); // Вызов метода displayMessage() класса GitHub
    

    return 0;
}

