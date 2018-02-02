/*
 * Class interface of
 */

/* 
 * File:   OperatorsLink.h
 * Author: ruslan
 *
 * Created on 30 января 2018 г., 20:27
 */

#ifndef OPERATORSLINK_H
#define OPERATORSLINK_H

#include"OperatorsBase.h"
#include <iostream>
#include <string>


using namespace std;

class OperatorsLink : public OperatorsBase {
    
    OperatorsLink();
    
    OperatorsLink(const string &aid1, const string &nameAid1);
    
    OperatorsLink(const string &aid1, const string &aid2, const string &nameAid1, const string &nameAid2);
    
    void workAid(const int &, const double &);
    
    
};

#endif /* OPERATORSLINK_H */
    

    
