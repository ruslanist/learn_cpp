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
    
    size_t len;
    
    std::cout << "Введите интересующее Вас количество символов в тексте" 
            << "Которые желаете вывести и сохронить" << std::endl;
    AString objekt1("Hello Word", 5);
    
	try {
		AString str("....TEST STRING #");
                AString str2 = str;
		std::cout << str.find_first_of('#') << std::endl;
		// str.find_last_of('T');
                std::cout << str.c_str() << std::endl;
                str.append("Helloy My Program").append("Go too Paty");
                str.prepend("I Just Do It!!!").prepend("Today We Do It!!!");
                std::cout << str.c_str() << std::endl;
	} catch(const NotImpl& e) {
		std::cout << e.what() << std::endl;
	}
    for(int i = 0; i < 20; i++){
        char* p = new char[8];
        memcpy(p, "Frend Helloxvbxbvxcvb", 8);
        AString objekt1(p, 8);
        delete[] p;
        std::cout << objekt1.c_str() << std::endl;
    }
    //std::cout << objekt1.find_first_not_of(' ');
    
    
    
}  
