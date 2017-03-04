cmake_minimum_required (VERSION 2.6)
project (FileManager)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(source_files 
	${PROJECT_SOURCE_DIR}/src/FileManager.cpp
	${PROJECT_SOURCE_DIR}/src/main.cpp
)
include_directories(AFTER ${PROJECT_SOURCE_DIR}/includes)
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


add_executable(${PROJECT_NAME} ${source_files})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
