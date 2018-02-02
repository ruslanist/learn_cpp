/*
 * Fail Implementations
 */

/* 
 * File:   OperatorsCpp.cpp
 * Author: ruslan
 *
 * Created on 30 января 2018 г., 20:08
 */

#include"OperatorsPointers.h"
#include"OperatorsLink.h"
#include"OperatorsBase.h"
#include"OperatorsInformation.h"


#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;


OperatorsPointers::OperatorsPointers() {}

OperatorsPointers::OperatorsPointers(const string &aid1, const string &nameAid1, const string descAid1, const string &aid2,  const string &nameAid2, const string descAid2) {

    setoperatorAid1(aid1);
    setoperatorName1(nameAid1);
    setoperatordescAid1(descAid1);
    setoperatorAid2(aid2);
    setoperatorName2(nameAid2);
    setoperatordescAid2(descAid2);
}

    void OperatorsBase::setoperatorAid1(const string &aid1) {
        fieldAid1 = aid1;
    }
        string OperatorsBase::getoperatorAid1() {
            return fieldAid1;
        }
               
    void OperatorsBase::setoperatorName1(const string &nameAid1) {
        fieldName1 = nameAid1;
   }
        string OperatorsBase::getoperatorName1(){
            return fieldName1;
        }
        
    void OperatorsBase::setoperatordescAid1(const string &descAid1) {
        descriptionAid1 = descAid1;
    }
        string OperatorsBase::getoperatordescAid1() {
            return descriptionAid1;
        }
        
    void OperatorsBase::setoperatorAid2(const string &aid2) {
        fieldAid2 = aid2;
    }
        string OperatorsBase::getoperatorAid2() {
            return fieldAid2;
        }
        
    void OperatorsBase::setoperatorName2(const string &nameAid2) {
        fieldName2 = nameAid2;
    }
        string OperatorsBase::getoperatorName2() {
            return fieldName2;
        }
        
    void OperatorsBase::setoperatordescAid2(const string &descAid2) {
        descriptionAid2 = descAid2;
    }
        string OperatorsBase::getoperatordescAid2() {
            return descriptionAid2;
        }

OperatorsLink::OperatorsLink() {}

OperatorsLink::OperatorsLink(const string &aid1, const string &nameAid1, const string &aid2,  const string &nameAid2) {

    //cout << "Введеные Вами данные: " << endl;
    
    //cout << "Индетификатор1: " << &nameAid1 << " " << "OID1 :" << &aid1<< endl;
    //cout << "Индетификатор2: " << &nameAid2 << " " << "OID2 :" << &aid2<< endl;
}

OperatorsLink::OperatorsLink(const string &aid1, const string &nameAid1) {

   // cout << "Введеные Вами данные: " << endl;
    
   // cout << "Индетификатор1: " << &nameAid1 << " " << "OID1 :" << &aid1<< endl;
}
    
   void OperatorsBase::operatoraidNameAll(const string& aid1, const string& nameAid1, const string& aid2, const string& nameAid2) const {
    
        cout << "Названия (Идентифекатор): " << aid1 << " -" << "Значение OID: " 
                << nameAid1 << endl;
        
        cout << "Названия2 (Идентифекатор): " << aid2 << " -" << "Значение OID2: " 
                << nameAid2 << endl;        
                
    }

    void OperatorsBase::operatoraidName(const string& aid1, const string& nameAid1) const {
    
        cout << "Названия (Идентифекатор): " << aid1 << " -" << "Значение OID: " 
                << nameAid1 << endl;
        
    }

   void OperatorsPointers::workAid(const int& parmAid1, const int& parmAid2) {
       
       int sum1 = 100;
       
       int sum2 = 200;
       
       int *poin1 = &sum1;
       
       int *poin2 = &sum2;
       
       int amount = (*poin1) * (*poin2);
       
       int amount2 = parmAid1 + parmAid2;
       
       cout << "Сумма введенных Вами данных = " << amount2  << endl;
       
       
       cout << "OID: " << parmAid2 << endl;
       
       cout << "Выражение равно: " << amount << endl;
   }     

   void OperatorsLink::workAid(const int& parmAid1, const int & parmAid2) {
       
      int amount2 = parmAid1 + parmAid2;
       
       int sum1 = 4000;
       
       int sum2 = 1000;
       
      int amount1 = sum1 + sum2;
       
       
       string Word1 = "Значение1 :";
       
       string Word2 = "Значение2 : ";
       
       
       string &Link1 = Word1;
       
       string &Link2 = Word2;
       
       int &Link3 = sum1;
       int &Link4 = sum2
       
       
       cout << "Сумма введенных Вами данных = " << amount2 << endl;
       
       cout << Word1 << sum1 << "По адрессу в памяти: " << &Link3 << endl;
       cout << Word2 << sum2 << "По адрессу в памяти: " << &Link4 << endl;
       
       
       cout << "Итоговая сумма вычисления =" << amount = (link3 + sum) * 2 << endl; 
       
   }  
   
   OperatorsInformation::OperatorsInformation() {}
   
   OperatorsInformation::OperatorsInformation(const string &aidInform, const string &mibInform) {
   
        setoperatorinfAid(&aidInform);
        setoperatorinfMib(&mibInform);       
   }
   
        void OperatorsBase::setoperatorinfAid(const string &aidInform) {
   
            informAid = aidInform;
        }
     
        string OperatorsBase::getoperatorinfAid() {
        
            return informAid;
        }
               
        void OperatorsBase::setoperatorinfMib(const string &mibInform) {
        
             informMib = mibInform;
        }
        
        string OperatorsBase::getoperatorinfMib() {
        
            return informMib;
        }
   
   
   
   void OperatorsInformation::aidInform() {
   
       cout << "OID (Object Identifier, идентификатор объекта) — это глобально уникальный номер, идентифицирующий объекты. Глобально-уникальный означает, что во всей вселенной существует единственная организация, отвечающая за определение объекта и его функциональность." << endl;
       cout << "Management Information Base (MIB, база управляющей информации) - виртуальная база данных, используемая для управления объектами в сети связи. Наиболее часто это понятие связывают с Simple Network Management Protocol (SNMP), но также оно используется в более широком смысле - в контексте модели управления сети OSI/ISO. Хотя термин MIB предназначен для обозначения всей доступной информации об объекте, он также часто используется для обозначения конкретного подмножества, которое правильнее называть MIB-модулем." << endl;
       
   }
   
   
   
   