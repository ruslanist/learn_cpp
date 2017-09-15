/*
 * Разделить интерфейс и реализацию на файлы AString.h и AString.cpp соответственно.
 * Создать отдельный файл main.cpp, и в него унести функцию main, которая задана ниже в коде
 * Создать Makefile , в нем создать команду для компиляции всех этих файлов в один бинарник
 * Реализовать find_last_of и проверить
*/

#include<stdexcept>
#include<iostream>
#include<cstring>
class NotImpl : public std::runtime_error {
	public:
		NotImpl(const char* reason) : std::runtime_error(reason) {}
};

class AString {
	public:
		const static size_t npos = -1;
		AString(const char* input) {
			bufLen = strlen(input);
			internBuf = new char[bufLen + 1 /*for '\0'*/];
			strcpy(internBuf, input);
		}
		~AString() {
	//		delete internBuf;
		}
		size_t find_first_of(char ch) const {
			for(size_t i = 0; i < bufLen; i++) {
				if(internBuf[i] == ch)
					return i;
			}
			return npos;
		}
		size_t find_last_of(char ch) const {
			throw NotImpl("'find_last_of' not implemented yet");
		}
		const char* c_str() const {
			return internBuf;
		}
	private:
		char * internBuf;
		size_t bufLen;
};

int main() {
	try {
		AString str("TEST STRING #");
		std::cout << str.find_first_of('#') << std::endl;
		str.find_last_of('T');
	} catch(const NotImpl& e) {
		std::cout << e.what() << std::endl;
	}
}
