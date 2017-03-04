#include <FileManager.h>
#include <stdexcept>
using namespace file_mgr;

//Задаем реализацию конструктора класса File, используя {список инициализации в конструкторе}
File::File(const std::string& name) : m_name(name) {}

//Задаем реализацию функции FindFileByName в классе LocalFileManager
File LocalFileManager::FindFileByName(const string &path_file) const {
    //Если мы не смогли найти нужный файл, то, используя {ключевое слово throw}, кидаем эксцепшен
    throw std::runtime_error("File: '" + path_file + "' not found");
}
