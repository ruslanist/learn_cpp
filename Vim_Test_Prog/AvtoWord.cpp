// Файл AvtoWorld.cpp Реализует Код путем наследования от абстрактного класса в хидере.
nclude <iostream>
using std:cout;
using std:endl;

#include <string>
using std:string;

i#include "vim_get_set.h"


// Наследник Абстрактног Класс AvtoInWorld - Русские Автомобили. 
class RussiaCars: public AvtoInWorld {

	RussiaCars::AvtoInWorld(const string marka, const string model, const string color, int cost, double month, double yer) 
	{
	 setMarkaCar(marka); 
         setModelCar(model);
         setColorCar(color);         // ИНЦИАЛИЗАЦИЯ ФУНКЦИЙ Set для данного класса.
	 setCostCar(cost);
	 setSellMonthCar(month);
	 setSellYerCar(yer);
	} // Завершение Конструктора.


}; // Заверщение Класса RussiaCars.


// Наследник Абстрактног Класс AvtoInWorld - Японские Автомобили. 
class JapanCars: public AvtoInWorld {

	JapanCars::AvtoInWorld(const string marka, const string model, const string color, int cost, double month, double yer)
        {
         setMarkaCar(marka);
         setModelCar(model);
         setColorCar(color);         // ИНЦИАЛИЗАЦИЯ ФУНКЦИЙ Set для данного класса.
         setCostCar(cost);
         setSellMonthCar(month);
         setSellYerCar(yer);
        } // Завершение Конструктора.


}; // Заверщение Класса JapanCars.


// Наследник Абстрактног Класс AvtoInWorld - Европейские Автомобили. 
class EuropCars: public AvtoInWorld {

	EuropCars::AvtoInWorld(const string marka, const string model, const string color, int cost, double month, double yer)
        {
         setMarkaCar(marka);
         setModelCar(model);
         setColorCar(color);         // ИНЦИАЛИЗАЦИЯ ФУНКЦИЙ Set для данного класса.
         setCostCar(cost);
         setSellMonthCar(month);
         setSellYerCar(yer);
        } // Завершение Конструктора.


}; // Заверщение Класса EvropCars.


// Наследник Абстрактног Класс AvtoInWorld - Корейские Автомобили. 
class CoreaCars: public AvtoInWorld {

	CoreaCars::AvtoInWorld(const string marka, const string model, const string color, int cost, double month, double yer)
        {
         setMarkaCar(marka);
         setModelCar(model);
         setColorCar(color);         // ИНЦИАЛИЗАЦИЯ ФУНКЦИЙ Set для данного класса.
         setCostCar(cost);
         setSellMonthCar(month);
         setSellYerCar(yer);
        } // Завершение Конструктора.


}; // Заверщение Класса CoreaCars:.







