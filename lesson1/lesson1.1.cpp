#include<iostream>
class Ruslan {
public:
	virtual void WakeUp() const {
		std::cout << "Базовый тип" << std::endl;
	}
	virtual void Drink() const {
		std::cout << "Базовый тип" << std::endl;
	}
	virtual void RunByCarToPervomaysk() const {
		std::cout << "Базовый тип" << std::endl;
	}
};

class RuslanBMV : public Ruslan {
public:
	void WakeUp() const {
		std::cout << "Встать с дивана" << std::endl;
	}
	void Drink() const {
		std::cout << "Выпить чай" << std::endl;
	}
	void RunByCarToPervomaysk() const {
		std::cout << "Сесть в БМВ и доехать до первомайского" << std::endl;
	}
};
class RuslanKAMAZ : public Ruslan {
public:
	void WakeUp() const {
		std::cout << "Встать с раскладушки" << std::endl;
	}
	void Drink() const {
		std::cout << "Выпить компота" << std::endl;
	}
	void RunByCarToPervomaysk() const {
		std::cout << "Сесть в КАМАЗ и доехать до первомайского" << std::endl;
	}
};

//Цель алгоритма поднять с кровати, напоить, посадить в машину и довести до первомайского. Напишем функцию perform_task, которая через ИНТЕРФЕЙС базового класса будет это все делать. Ее не интересует что за машина, с какой кровати, что он удет пить. Ей важен сам алгоритм, сама правильная последовательность действий - что вначале встать, выпить, поехать.
void perform_task(const Ruslan& r) {
	r.WakeUp(); //А почему он тут не выводит строчку "Базовый тип", ведь здесь мы вроде бы как обращаемся к объекту Ruslan, у которого WakeUp выводит "Базовый тип"? А дело то как раз в виртуальной функции. 
//perform_task ожидает в качестве параметра объект класса Ruslan, но по факту, мы ему подкладываем например RuslanBMV. И он это хавает! Потому что RuslanBMV является дочерним классом для Ruslan. ЭТо и называется работа через базовый класс, когда ты вызываешь методы базового класса (Ruslan), а по факту, отрабатывают методы заданного конкретного класса
	r.Drink();
	r.RunByCarToPervomaysk();
}

int main() {
	//Директор сказал что нужно на камазе
	RuslanKAMAZ rk;
	perform_task(rk);

	std::cout << std::endl;
	//Директор сказал, что нужно теперь на БМВ. Мы поменяли класс на бмв, но сама функция perform_task осталась не изменной, нам не пришлось ее менять, потому что она работает через интерфейс базового класса.
	RuslanBMV rb;
	perform_task(rb);
}

