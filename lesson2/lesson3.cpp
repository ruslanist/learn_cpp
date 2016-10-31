#include<string>
#include<iostream>
//Разберись с тем, как работает функция GetWord.
//Что бы это сделать, начни с main. Просто иди по строчкам и смотри, что каждая строчка делает.
//Компьютер испольняет инструкции последовательно, так-же, начиная с main он идет и делает каждую строчку.

/*
Рассмотрим какие должны быть рассуждения в голове, на примере вот этой строчки кода

std::cout << "Вывод первого вызова: " << GetWord(test_str) << std::endl;

Итак, вначале идет cout, ты знаешь что он делает. Затем следом за этим сиаутом и строчкой 'Вывод первого вызова:'
 ты видишь 'GetWord(test_str) << std::endl;'
Вот этот кусочек 'GetWord(test_str)' Это вызов функции. Вызов функции, это значит, что процессор "прыгает" в реализацию функции GetWord. И ты должен сделать тоже самое. Это значит, что ты должен переметнуться взглядом на строчку кода, где начинается реализация GetWord, вот эта строчка

'string GetWord(string& input_str) {'
Теперь, ты уже в этой функции идешь по строчкам, последовательно. 
Вот ты видишь создание переменной retval с типом string
'string retval;'
За ней ты видишь строчку
'size_t begin = input_str.find_first_not_of(" \n\t"); //www.cplusplus.com/reference/string/string/find_first_not_of/'

Здесь ты видишь, что создается переменная begin, ее тип string и то, что мы ей присваиваем, это результат выполнения функции 
'input_str.find_first_not_of(" \n\t");'

То есть мы присваиваем не саму функцию, а то, что она возвращает.
Когда компилятор видит вот такое выражение
int a = foo(); 
Он создает переменную a, затем "прыгает" в функциюю foo(), делает ее код, исполняет построчно ее код, как код main, а затем, внимание! он возвращается в момент присваиивания

int a = 'я вернулся из функции foo() и принес из нее результат, который она отдала командой return'

Возвращаемся к нашей конструкции
'input_str.find_first_not_of(" \n\t");'
'find_first_not_of' - это метод у объекта 'input_str'.
Погугли что он делает. Он ищет индекс первого символа в строке, отличного от символов: ' ', '\n', '\t'

в итоге
size_t begin = 'присвоится либо индекс символа либо string::npos, если нет символа отличного от вот этих символов ' ', '\n', '\t''

Дальше ты видишь как раз проверку
if(begin != string::npos) { <----- Если в begin НЕ npos(т.е. мы нашли символ), то мы делаем что-то.

ИНАЧЕ
else {
input_str.clear(); <-----Мы очищаем исходную строку и уходим
}
*/
using std::string;
//Эта функция выдирает из input_str одно слово. То есть она ищет в строке любой символ, отличный от этих ' ', '\n', '\t'.
//Найденный символ трактуется как начало слова. Затем, она ищет конец слова, путем поиска одно из символов ' ', '\n', '\t'
//В результате функция возвращает слово и одвноременно с этим из исходной строки это слово удаляется.
//Если в строке нет слов, там только пробелы - то вся строка очищается(input_str.clear() и она становится пустой"
string GetWord(string& input_str) {
	string retval;
	size_t begin = input_str.find_first_not_of(" \n\t"); //www.cplusplus.com/reference/string/string/find_first_not_of/
	if(begin != string::npos) {
		input_str = input_str.substr(begin);
		size_t end = input_str.find_first_of(" \n\t");
		if (end != string::npos) {
			retval = input_str.substr(0, end);
			input_str = input_str.substr(end); 
		} else {
			retval = input_str;
			input_str.clear();
		}
	} else {
		input_str.clear();
	}
	return retval;
}
int main() {
	//Используя GetWord найти слово FIND_ME в строке test_str и вывести его
	string test_str = "AAA BBB CCCCCCC XXZCZXCX        \t     \n   \t   FIND_ME asdasdasd  zxc zxc zxc  dfr g 4 d\t \n ";
	std::cout << "Вывод исходной строчки до всяких действий: " << test_str << std::endl;
	std::cout << "Вывод первого вызова: " << GetWord(test_str) << std::endl;
	std::cout << "Вывод второго вызова: " << GetWord(test_str) << std::endl;
	std::cout << "Вывод того, что осталось в исходной строчке: " << test_str << std::endl;
	while(!test_str.empty()) {
		//Какие то действия с GetWord()
		if (/*какое то условие*/) {
			std::cout << "ЗДЕСЬ ВЫВОД FIND_ME" << std::endl;
		}
	}
}
