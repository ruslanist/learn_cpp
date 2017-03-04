#include <FileManager.h>

#include <stdexcept>
#include<iostream>
#include<memory>
using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: ./prog file" << std::endl;
        return 1;
    }
    //Используя {оператор new} мы создаем объект LocalFileManager и оборачиваем его в объект класса {std::shared_ptr}
    std::shared_ptr<file_mgr::FileManager> file_manager(new file_mgr::LocalFileManager);
    try {
        file_mgr::File file = file_manager->FindFileByName(argv[1]);
        cout << "YES" << endl;
    } catch(const std::runtime_error& e) {
        //Мы перехватываем эксцепшен, который может кинуть FindFileByName и выводим объяснение эксцепшена
        cout << e.what() << endl;
    }
    return 0;
}
