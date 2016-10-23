/*Если сейчас скомпилировать прогамму и запустить ее, то она выведет:
Велосипед b1
Велосипед b2
Коньки s1

Добавь объект Велосипед с именем b3 и еще одни Коньки с именем s2 таким образом, что бы программа выводила
Велосипед b1
Велосипед b2
Коньки s1
Велосипед b3
Коньки s2

Что бы все это сделать, тебе необходимо повторить и изучить следующие темы в гугле

Что такое std::string?
Что означает ключевое слово virtual?
Что такое указатель в C++
Передача параметров по ссылке и по значению в C++
Что такое typedef в C++
Ключевое слово const
Контейнер std::vector в C++.
Метод push_back у std::vector в C++.
Наследование в C++ . Публичное наследование в C++.
http://logic.pdmi.ras.ru/~smal/aptu/cpp10/2010_11_26.html
*/

#include<string>
#include<iostream>
#include<vector> // Подключение для использования Вектора абстрактная модель 
using std::string;  // динамических масивов

class Item {
public:
	Item(const string& name) { // Создает пустую строку (Конструктор)
		_name = name;
	}
	string GetName() const {  // Метод
		return _name;
	}
	virtual string PrintDescription() const {  // Виртуальный метод string
		return "";                         // константный
	}
private:
	string _name; // Пустая строка string
};

class Bicycle : public Item {
public:
	Bicycle(const string& name) : Item(name) {};
	string PrintDescription() const {
		return "Велосипед " + GetName();
	}
};

class Skates : public Item {
public:
	Skates(const string& name) : Item(name) {};
	string PrintDescription() const {
		return "Коньки " + GetName();
	}
};

class Sanki : public Item {
public:
	Sanki(const string& name) : Item(name) {};
	string PrintDescription() const {
		return "Санки " + GetName();
	}
};

class Snowbord : public Item {
public:
	Snowbord(const string& name) : Item(name) {};
	string PrintDescription() const {
		return "Сноу-Борд " + GetName();
	}
};

int main() {
	std::vector<Item*> item; // Объявление пустого вектора типа Item
	Bicycle b1("b1");
	Bicycle b2("b2");
        Bicycle b3("b3");
	Skates s1("s1");
        Skates s2("s2");
        Sanki sn1("sn1");
        Sanki sn2("sn2");
        Sanki sn3("sn3");
	Snowbord snow1("snow1");
        Snowbord snow2("snow2");
        Snowbord snow3("snow3");     
        
	item.push_back(&b1);
	item.push_back(&b2);
        item.push_back(&b3);
	item.push_back(&s1);
        item.push_back(&s2);
        item.push_back(&sn1);
        item.push_back(&sn2);
        item.push_back(&sn3);
        item.push_back(&snow1);
        item.push_back(&snow2);
        item.push_back(&snow3);
	for(int i = 0; i < item.size(); i++) { // Цикл lkz выводf значения b и s
		std::cout << item[i]->PrintDescription() << std::endl;
	}
}