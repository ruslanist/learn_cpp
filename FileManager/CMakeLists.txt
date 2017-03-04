cmake_minimum_required (VERSION 2.6)
#Назвали проект
project (FileManager)

#Указали компилятору, что мы используем 11 стандарт с++
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#Задали исходные файлы для компиляции. Ниже, к списку исходных файлов для компиляции будут обращаться через переменную {source_files}
set(source_files 
	${PROJECT_SOURCE_DIR}/src/FileManager.cpp
	${PROJECT_SOURCE_DIR}/src/main.cpp
)

#Указали, где лежат заголовные файлы(хидеры) нашего проекта.
#Переменная PROJECT_SOURCE_DIR хранит в себе путь к каталогу с проектом
include_directories(AFTER ${PROJECT_SOURCE_DIR}/includes)

#Команда, что бы найти хидеры и библиотеки  буста
find_package(Boost REQUIRED COMPONENTS system filesystem)
if (Boost_FOUND)
  # From the offical documentation:
  # Add include directories to the build. [...] If the SYSTEM option is given,
  # the compiler will be told the directories are meant as system include
  # directories on some platforms (signalling this setting might achieve effects
  # such as the compiler skipping warnings [...])."
  include_directories (SYSTEM ${Boost_INCLUDE_DIR})

  # From the offical documentation:
  # "Specify directories in which the linker will look for libraries. [...] Note
  # that this command is rarely necessary. Library locations returned by
  # find_package() and find_library() are absolute paths. Pass these absolute
  # library file paths directly to the target_link_libraries() command. CMake
  # will ensure the linker finds them."
  link_directories (${Boost_LIBRARY_DIRS})
else()
    message("Boost_FOUND NOT FOUND")
endif ()


#Указывает скомпилировать программу с именем, которое хранится в ${PROJECT_NAME} на основе исходных файлов из ${source_files}
#В нашем случае переменная PROJECT_NAME хранит строку FileManager
add_executable(${PROJECT_NAME} ${source_files})

#Прилинковать бустовые библиотеки к программе
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
