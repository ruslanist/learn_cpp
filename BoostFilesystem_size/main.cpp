/*
 * Данная программа выводит содержание и размер файлов в указанной директории
 */

/* 
 * File:   main.cpp
 * Author: ruslan
 *
 * Created on 2 марта 2017 г., 16:29
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>

#include "boost/filesystem.hpp"
using namespace boost::filesystem;
using boost::filesystem::path;

namespace fs = boost::filesystem;


void print_dir(const std::string dir)
    {
    
    directory_iterator end_itr; 
    
           
            for ( directory_iterator itr( dir );
                      itr != end_itr;
                      ++itr )                               
                {    
                    if( is_directory(itr->status()) ) 
                        {
                            if ( file_size( itr->path()) ) return true;
                        } 
                    
                        else if (is_regular_file(itr->status()))
                        {
                            
                            cout << itr->path() << endl; 
                            cout << fs::file_size(itr->path() ) << endl;
                            
                        return true;    
                        }   
                }
                                    
    }

int file_size(int argc, char* argv[] ) 

        {
            if ( argc != 2 )
  {
    std::cout << "Usage: file_size path\n";
    return 1;
  }

  std::cout << "sizeof(intmax_t) is " << sizeof(boost::intmax_t) << '\n';
// intmax_t позволяет работать с переменной не известного размера 
  fs::path p( argv[1] );

  if ( !fs::exists( p ) )
  {
    std::cout << "not found: " << argv[1] << std::endl;
    return 1;
  }

  if ( !fs::is_regular( p ) ) /***********************************/
  {
    std::cout << "not a regular file: " << argv[1] << std::endl;
    return 1;
  }
 
  std::cout << "size of " << argv[1] << " is " << fs::file_size( p )
    << std::endl;
        }

bool find_file( const path & dir_path,         // in this directory,
                const std::string & file_name, // search for this name,
                path & path_found )            // placing path here if found
{
    
            if ( !exists( dir_path ) ) return false;
            directory_iterator end_itr; // default construction yields past-the-end
            for ( directory_iterator itr( dir_path );
                  itr != end_itr;
                  ++itr )
            { 
                try {
                        if ( is_directory(itr->status()) )
                        {
                          if ( find_file( itr->path(), file_name, path_found ) ) return true;
                        }
                        else if (is_regular_file(itr->status()) && itr->path().filename().string() == file_name ) // see below
                        {
                          path_found = itr->path();
                          return true;
                        } 
                } catch(const filesystem_error& e) { cout << e.what() << endl; } 
            }
            return false;

}

int main (int argc, char* argv[]) {
 
     print_dir(argv[1]);
     
     
    return 0;
}