/*
 * Фаил запускающий программу netsnmp
 */

/* 
 * File:   main.cpp
 * Author: ruslan
 *
 * Created on 8 июня 2017 г., 1:36
 */

#include <string>
using std::string;

#include"netsnmp.h"




/*
 * 
 */
int main(int argc, char** argv) {
    
    
    NetSnmp snmp_object();
    
    snmp_object.snmp_manager();

    return 0;
}


