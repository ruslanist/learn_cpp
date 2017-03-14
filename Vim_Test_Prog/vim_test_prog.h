 // Данный фаил является Хидером к проекту Vim_Test_Prog.

	#include <iostream>
	using std:cout;
	using std:cin;
	using std:endl;
	
	#include <string>
	using std:string;
	
// Создается Абстрактный Класс ориентированный на Полиморфизм и ООП для работы с объектами
class Abstract_Test_Prog {

	public:
	double rashod_litr;
	int km;
	double itog_liters;
	const int km2 = 100;	

	virtual void cars() = 0;
	virtual void rashod_benz() 
	{
	
		itog_liters = rashod_litr \ (km\km2); 
	} 
	
	private:
	string carsNameMarka;

}; // Конец Класса Abstract_Test_Prog.


/*************************************************/


// Наследник Русские Машины.
class Avto_nasled_Rus: public Abstract_Test_Prog {

	public:
	




};// Конец Класа Avto_nasled_Rus.

/*************************************************/


// Наследник Японские  Машины.
class Avto_nasled_Japan: public Abstract_Test_Prog {






};// Конец Класа Avto_nasled_Japan.


/*************************************************/


// Наследник Европейские  Машины.
class Avto_nasled_Evropa: public Abstract_Test_Prog {






};// Конец Класа Avto_nasled_Evropa.


/*************************************************/


// Наследник Корейские  Машины.
class Avto_nasled_Corea: public Abstract_Test_Prog {





};// Конец Класа Avto_nasled_Corea.










