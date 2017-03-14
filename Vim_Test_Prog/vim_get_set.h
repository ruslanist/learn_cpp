
// Данный Фаил объявляет Абстрактный Класс, с его конструктором, и методами.

#ifndef AVTOINWORLD_H
#define AVTOINWORLD_H

#include <iostream>
using std:cout;
using std:endl;
 
#include <string>
using std:string;

// Абстрактный Класс Автомобилии Мира.
class AvtoInWorld 
{
   public: 
  
      AvtoInWorld(const string &, const string &, const string &, int = 0, double = 0.0, double = 0.0);	

	void setMarkaCar(const string &); // Установка названия марки автомобиля.
	string getMarkaCar() const; // Возврат марки.

	void setModelCar(const string &); // Установка названия модели автомобиля.
	string getModelCar() const; // Возврат модели.

	void setColorCar(const string &); // Установка названия цвета  автомобиля.
	string getColorCar() const; // Возврат цвета.

	void setCostCar(int); // Установка цены автомобиля.
	int getCostCar() const; // Возврат цены.

	void setSellMonthCar(double); // Установка продаж в месяц  автомобиля.
	double getSellMonthCar() const; // Возврат продаж в месяц.

	void setSellYerCar(double); // Установка продаж в год  автомобиля.
	double getSellYerCar() const; // Возврат продаж в год.

	virtual double rashodToplivo() const; // Вычисляет расход Топлива.
	{
	 cout << "Cars of Land World" << endl;
	}
	
	virtual void print() const; // Напечатать объект.
	{
	 cout << "Our program can print more information of you car!" << endl;
	}

	virtual void garantiyaCar() = 0; // Выводит  гарантийный срок автомобиля.

   private:
      
      string markaCar; 
      string modelCar;
      string colorCar;
      int costCar;
      double sellyerCar;
      double sellmonthCar;
            
}; // Конец Абстрактного Класса AvtoInWorld.


#endif
