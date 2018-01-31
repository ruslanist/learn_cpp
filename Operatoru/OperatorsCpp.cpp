/*
 * Fail Implementations
 */

/* 
 * File:   OperatorsCpp.cpp
 * Author: ruslan
 *
 * Created on 30 января 2018 г., 20:08
 */

#include "OperatorsLink.h"
#include "OperatorsPointers.h"

#include <iostream>
using std::cout;
using std::endl;


#include <string>
using std::string;

#include "OperatorsBase.h"

OperatorsPointers::OperatorsPointers(const string &aid1, const string &aid2, string &nameAid1, string &nameAid2, int name1, double name2) {

    OperatorsPointers::operatorAid1(const string &aid1) {
        
        fieldAid1 = aid1;
        cout << aid1 << endl;
    }
    
    OperatorsPointers::operatorAid2(const string&aid2) {
        
        fieldAid2 = aid2;
        cout << aid2 << endl;
    }
    
    OperatorsPointers::operatorName1(string &nameAid1) {
    
        fieldName1 = nameAid1;
        cout << nameAid1 << endl;
    }
    
    OperatorsPointers::operatorName2(string &nameAid2) {
    
        fieldName2 = nameAid2;
        cout << nameAid2 << endl;
    }
    
    OperatorsPointers::workAid(int name1, double name2) {
    
        
        OperatorsBase obj;
        
        OperatorsPointers  objAid;
        
        OperatorsLink allAid;
    }

};


OperatorsLink::OperatorsLink(const string &aid1, const string &aid2, string &nameAid1, string &nameAid2, int name2, double name3) {

    OperatorsLink::operatoraidName1(const string &aid1, string &nameAid1) {
    
        cout << aid1 << nameAid1 << endl;
    }

    OperatorsLink::operatoraidName2(const string&aid2, string &nameAid2) {
    
        cout << aid2 << nameAid2 << endl;
    }

    OperatorsLink::operatoraidNameAll(const string &aid1, string &nameAid1, const string &aid2, string &nameAid2) {
    
        cout << aid1 << nameAid1 << aid2 << nameAid2 << endl;
    }
    
    OperatorsLink::workAid(int name2, double name3) {
    
    }
};
