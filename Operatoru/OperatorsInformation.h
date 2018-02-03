/*
 * A Class interface of the OperatorsInformation
 */

/* 
 * File:   OperatorsInformation.h
 * Author: ruslan
 *
 * Created on 2 февраля 2018 г., 18:59
 */

#ifndef OPERATORSINFORMATION_H
#define OPERATORSINFORMATION_H

#include"OperatorsBase.h"

#include <iostream>

using namespace std;

class OperatorsInformation : public OperatorsBase {

public:
    
    OperatorsInformation();
       
    void aidInform();
    
};

#endif /* OPERATORSINFORMATION_H */

