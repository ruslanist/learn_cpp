/*
 * Задача 2: Приложение на вход принемает Аргумент в виде строковых 
 * символов char, далее обходя массив аргументов argv программа будет сохронять 
 * в вектор только целочисленые аргументы. Остальные будут игнорироваться.
 */

#include <cstdlib>

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

int main(int argc, char** argv)
   {

    vector<int> myint_Vec;

    for(int i=0; i<=argc; i++)
   	{

         int Num = 0;
	 
	 if(Num = atoi(argv[i]))
		{

		 myint_Vec.push_back(Num);

		} else 
		   {

		    cout << "You did not enter more than one argument " << endl;
                    cout << "Try the arguments again" << endl;

		   }

	}
 
    for(int j=0; j<myint_Vec.size(); j++)
	{

	 cout << "Вывод списка  сохраненных аргументов в вектори (myint_Vec), типа (int)" << endl;
	 cout << j << " " << myint_Vec[j] << endl;

	}

	return 0;
   }
