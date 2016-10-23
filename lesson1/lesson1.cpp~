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
#include<vector>
using std::string;

class Item {
public:
	Item(const string& name) {
		_name = name;
	}
	string GetName() const {
		return _name;
	}
	virtual string PrintDescription() const {
		return "";
	}
private:
	string _name;
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
	std::vector<Item*> item;
	Bicycle b1("b1");
	Bicycle b2("b2");
	Skates s1("s1");
	
	item.push_back(&b1);
	item.push_back(&b2);
	item.push_back(&s1);
	for(int i = 0; i < item.size(); i++) {
		std::cout << item[i]->PrintDescription() << std::endl;
	}
}
