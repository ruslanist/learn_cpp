/*
 * A Class interface of the OperatorsPointers
 */

/* 
 * File:   OperatorsPointers.h
 * Author: ruslan
 *
 * Created on 30 января 2018 г., 20:19
 */

#ifndef OPERATORSPOINTERS_H
#define OPERATORSPOINTERS_H

#include"OperatorsBase.h"

#include <iostream>
#include <string>

using namespace std;





class OperatorsPointers : public OperatorsBase {
    
public: 
    
    OperatorsPointers();
    
    OperatorsPointers(const string &aid1, const string &nameAid1, const string descAid1, const string &aid2,  const string &nameAid2, const string descAid2, const string &infAid, const string &infMib, 
                      const string &svitchname, const string &svitchIP, const string &svitchOS, const string &servername, const string &serverIP, const string &serveroS);
      
    void aidInform();
    
};   




#endif /* OPERATORSPOINTERS_H */
    
   
