// Данная программа ринемает на входе  парамметры с разными типами
// и далее выводитвсе  параметры на терминал.
 
#include <cstdlib>

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

 int main(int argc, char** argv) 
	{

	   for(int i=1; i<=argc; i++)

		{

		   if(argc > 1)
		
			{

			   cout << "Вывод Аргументов" << endl;
			   cout << argv[i] << endl; 		

			} else 

				{

				   cout << "You did not enter more than one argument" << endl;
				   cout << "Try the arguments again" << endl;		

			        }		
		}	 

return 0;

	}

	
