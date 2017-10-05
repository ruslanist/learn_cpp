/*
 * Разделить интерфейс и реализацию на файлы AString.h и AString.cpp соответственно.
 * Создать отдельный файл main.cpp, и в него унести функцию main, которая задана ниже в коде
 * Создать Makefile , в нем создать команду для компиляции всех этих файлов в один бинарник
 * Реализовать find_last_of и проверить
*/

#include<stdexcept>
#include<iostream>
#include<cstring>
#include "AString.h"

int main() {
	try {
		AString str("TEST STRING #");
		std::cout << str.find_first_of('#') << std::endl;
		str.find_last_of('T');
	} catch(const NotImpl& e) {
		std::cout << e.what() << std::endl;
	}
}