#include<iostream>
#include<vector>
using std::string;
using std::cout;
using std::vector;
using std::endl;

class Human {
	public:
		virtual string getName() = 0;

		virtual int getAge() = 0;
};

class Bob : public Human {
	public:
		virtual string getName() {
			return "Bob"; //переопределили чисто виртуальную функцию, задали свое тело, актуальное для класса Bob
		}

		virtual int getAge() {
			return 33;
		}
};

class Alis : public Human {
	public:
		virtual string getName() {
			return "Alis";
		}

		virtual int getAge() {
			return 40;
		}
};

class UnknownMan : public Human {
	public:
		virtual string getName() {
			return ""; //Не известный человек, его имя - не известно. Возвращаем пустую строку
		}
		
		virtual int getAge() {
			return 0;
		}
};

int main() {
	vector<Human *> human; //создали вектор с именем human, его тип vector<Human *> - т.е. он несет внутри себя элементы - указатели на Human.
	human.resize(5); //Выделили место в векторе под 5 элементов.

	Alis alis;
	Bob bob;
	UnknownMan unk;

	human.push_back(&alis); //положили указатель на элис в вектор
	human.push_back(&bob);
	human.push_back(&unk);	

	for(int i = 0; i < human.size(); i++) {
		cout << "Имя: " << human[i] << endl;
	}
}