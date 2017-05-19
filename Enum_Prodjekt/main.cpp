/* Программа демонстрирует Тип Перечесления (enum), на премере
*  работы виртуальног лифта.
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// Создание переменную  для выбора этажа с типом перечесления enum.
enum level {parking = 1, supermarket, clubRestaurant, bar,  kid_floor, cinima};

int main()

{

	setlocale(LC_ALL, "rus");

   level floor = parking; // Переменная типа перечесления level.
   int take_fl = floor; // Кнопка выбора нужного  этажа клиентом.
   bool exit = true; // Выбор пользователем, выдти из лифта  или продолжить.
   
	cout << "Добро пожаловать в Наш  развлекательный центр СильверМол" << endl;
	cout << "Предлогаем вам проехаться в лифте  и посетить все этажи Гипермаркета СильверМол!" << endl;

	cout << "В развлекательном торговом центре СильверМол вы можете посетить" << endl;

	cout << "Авто - Парковка" <<parking<< "-ый Этаж" <<  endl;
	cout << "Супермаркет" <<supermarket<< "-ой Этаж" <<  endl;
	cout << "Клуб и ресторан" <<clubRestaurant<< "-ий Этаж" << endl;
	cout << "Бар" <<bar<< "-ый Этаж" << endl;
	cout << "Детская комната"<<kid_floor<< "-ый Этаж" << endl;
	cout << "Кинозал"<<cinima<< "-ой Этаж" << endl;
    	

	while(exit) // Пока exit = true, цикл будет выполняться.
	{
		cout << "Выберите нужный этаж нажав кнопку от 1 - 6" << endl;
		cin >> take_fl;

		switch(take_fl)
		{

		  case(parking):

		  	cout << "Добропжаловать на 1-ый этаж Авто-Парковки!" << endl;

       		  break;

		  case(supermarket):

                        cout << "Вы находитесь на 2-ом этаже в Супермаркете SPAR" << endl;

                  break; 

		  case(clubRestaurant):

                        cout << "Вы на 3-ем этаже в Ресторане- Елки-Палки" << endl;

                  break; 

		 case(bar):

                        cout << "Вы находитесь на 4-ом этаже в Баре - Gold Beear" << endl;

                  break; 

		  case(kid_floor):

                        cout << "Вы посетили 5-ом этаж Детской развлекательной комнаты" << endl;

                  break; 

		  case(cinima):

                        cout << "Вы находитесь на 6-ом этаже -Кинотиатра СилверМол" << endl;

                  break; 

 
			default: cout << "вы ввели не правельно этаж, попробуйте еще раз" << endl;

		}

		cout << "Если вы хотите выйте на этом этаже нажмите цифру (0)" << endl;
		cout << "Если Вы желаете продолжить ажмите цифр:у  (1)" << endl;
		cin >> exit;
		

	} // Завершения Цикла while

	return 0;
}
