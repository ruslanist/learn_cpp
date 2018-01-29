/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OperatoruBase.h
 * Author: ruslan
 *
 * Created on 29 января 2018 г., 16:06
 */

#ifndef OPERATORUBASE_H
#define OPERATORUBASE_H
#include <iostream>

using std::string;

class OperatorCPlus {
    
public:
    
    OperatorCPlus(int const &aid1, const int &aid2, string &nameAid1, string &Aid2);
    
    OperatorCPlus(int const &aid1, const int &aid2);
    
    OperatorCPlus(string &nameAid1, string &Aid2);
    
    OperatorCPlus(int const &aid1, const int &aid2, string &nameAid1);
    
    
    
        int operatorAid1(int &aid1) const;
    
        int operatorAid1(int &aid1, int &aid2);
    
        string operatorName(string &nameAid1) const;
    
        string operatorName(string &nameAid1, string &Aid2);
        
private:        
  
    int poleAid1;

    int poleAid2;
    
    string poleName1;
    
    string poleName2;
    
    
};


#endif /* OPERATORUBASE_H */

