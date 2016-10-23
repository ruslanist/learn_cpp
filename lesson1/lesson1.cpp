/*Если сейчас скомпилить программу и запустить, то она выведет
Базовый тип
Базовый тип
Базовый тип
Базовый тип
Базовый тип

Твоя задача дописать что-то в коде, что бы в случае вызова PrintType у объекта типа Bicycle выводилась фраза "Велосипед", а при вызове у объекта типа Skates - "Коньки"
Т.е. получится при запуске что-то вроде
Велосипед
Велосипед
Велосипед
Коньки
Коньки

При этом, сам цикл, который вот этот в main:
        for(int i = 0; i < item.size(); i++) {
                std::cout << item[i]->PrintType() << std::endl;
        }
трогать не надо, он должен остаться таким, какой он есть сейчас. 
*/

/*
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
	Item(const string& name) { // Создает пустую строку
		_name = name;
	}
	string GetName() const {
		return _name;
	}
	virtual string PrintDescription() const {  // Виртуальный метод string
		return "";                         // константный
	}
	string PrintType() const {
		return "Базовый тип";
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

int main() {
	std::vector<Item*> item; // Объявление пустого вектора типа Item
	Bicycle b1("b1");
	Bicycle b2("b2");
        Bicycle b3("b3");
	Skates s1("s1");
        Skates s2("s2");
	
	item.push_back(&b1);
	item.push_back(&b2);
        item.push_back(&b3);
	item.push_back(&s1);
	item.push_back(&s2);
	for(int i = 0; i < item.size(); i++) { 
		std::cout << item[i]->PrintType() << std::endl;
	}
}
