#include<string>
using std::string;

//Создаем свой namespace, где будут лежать наши классы
namespace file_mgr {
    class File {
    public:
        File(const std::string& name);
    private:
        std::string m_name;
    };

    //FileManager - это {абстрактный класс}. Потому что в нем есть {чисто виртуальная функция} FindFileByName.
    //Она так-же является {константным методом}
    //FileManager - это {базовый класс}
    class FileManager {
    public:
        /**
         * Эта функция используется для поиска файла. Если она не может найти файл, то кидает эксцепшен std::runtime_error
         * @param path_file имя файла для поиска
         * @return функция возвращает найденный файл в виде объекта класса File
         */
        virtual File FindFileByName(const string& path_file) const = 0;
    };

    //LocalFileManager - использует {публичное наследование} от базового класса FileManager.
    //Он реализует чисто виртуальную функцию FindFileByName.
    class LocalFileManager : public FileManager {
    public:
        virtual File FindFileByName(const string& path_file) const;
    };
} //end namespace file_manager
