/*
 * Base Class Operating System
 */

/* 
 * File:   OperatorsBase.h
 * Author: ruslan
 *
 * Created on 30 января 2018 г., 20:14
 */

#ifndef OPERATORSBASE_H
#define OPERATORSBASE_H

#include<stdexcept>
#include <iostream>

using std::string;

class OperatorsBase {
    
public:
        
        string operatorAid1(const string &aid1);
        
        string operatorAid2(const string &aid2);
        
        string operatorName1(string &nameAid1);
    
        string operatorName2(string &nameAid2);
    
        void operatoraidName1(const string &aid1, string &nameAid1) const;
        
        void operatoraidName2(const string &aid2, string &nameAid2) const;
        
        void operatoraidNameAll(const string &aid1, string &nameAid1, const string &aid2,  string &nameAid2) const;
        
        virtual void workAid() = 0;
        
  
    string fieldAid1;

    string fieldAid2;
    
    string fieldName1;
    
    string fieldName2;
    
    
    
    
};

#endif /* OPERATORSBASE_H */

