/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OperatorsInformation.h
 * Author: ruslan
 *
 * Created on 2 февраля 2018 г., 18:59
 */

#ifndef OPERATORSINFORMATION_H
#define OPERATORSINFORMATION_H

class OperatorsInformation : public OperatorsBase {

    OperatorsInformation();
    
    OperatorsInformation(const string &aidInform, const string &mibInform);
    
    void aidInform();

};



#endif /* OPERATORSINFORMATION_H */

