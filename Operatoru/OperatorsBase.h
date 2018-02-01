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

#include <iostream>
#include <string>

using std::string;

class OperatorsBase {
    
public:
        
        void setoperatorAid1(const string &);
        string getoperatorAid1();
               
        void setoperatorName1(const string &);
        string getoperatorName1();
        
        void setoperatordescAid1(const string &);
        string getoperatordescAid1();
        
        void setoperatorAid2(const string &);
        string getoperatorAid2();
        
        void setoperatorName2(const string &);
        string getoperatorName2();
        
        void setoperatordescAid2(const string &);
         string getoperatordescAid2();
        
        
        
        void operatoraidName(const string &aid1, const string &nameAid1) const;
        
        void operatoraidNameAll(const string &aid1, const string &nameAid1, const string &aid2,  const string &nameAid2) const;
        
        virtual void workAid(const int &, const double &) = 0;
        
private:
    
    string fieldAid1;
    
    string fieldName1;

    string fieldAid2;
    
    string fieldName2;
    
    string descriptionAid1;
            
    string descriptionAid2;      
    
    
    
    
};

#endif /* OPERATORSBASE_H */

