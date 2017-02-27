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
    if ( is_directory(itr->status()) )
    {
      if ( find_file( itr->path(), file_name, path_found ) ) return true;
    }
    else if ( itr->leaf() == file_name ) // see below
    {
      path_found = itr->path();
      return true;
    }
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
    
    bool find_file(dir_path, file_name, path_found);
    

    return 0;
}

