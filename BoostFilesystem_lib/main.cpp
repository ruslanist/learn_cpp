/*
 * Demonstration programs using Boost library named Filesystem
 */

/* 
 * File:   main.cpp
 * Author: ruslan
 *
 * Created on 27 февраля 2017 г., 1:22
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>

#include "boost/filesystem.hpp"
using namespace boost::filesystem;
using boost::filesystem::path; /*Снял Коммент*/

/*
void print_dir(const std::string dir)
    {
    
    directory_iterator end_itr; 
    for ( directory_iterator itr( dir );
                  itr != end_itr;
                  ++itr )
            {
                cout << itr->path() << endl; 
            }
    } */


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



int main(int argc, char** argv) {
    
    std::string dir_path;
    std::string file_name;
    path path_found;
    
    cout << "   Enter you wondering DIRECTIVE" << endl;
    cin >> dir_path;
    
    cout << "Enter you wondering file" << endl;
    cin >> file_name;
    
    if ( find_file(dir_path, file_name, path_found) )
        {
        cout << "YES" << endl;
        } else
            {
            cout << "NO" << endl;
            }

    /*
    print_dir(argv[1]);*/
    
    return 0;
}

