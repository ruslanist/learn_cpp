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

   void OperatorsPointers::workAid(const int& parmAid1, const double& parmAid2) {
       
       int *poin1 = 100;
       
       size_t *poin2 = 200;
       
       int amount = 0;
       
       double amount2;
       
      cout << "Сумма введенных Вами данных = " << amount2 = parmAid1 + parmAid2 << endl;
       
       cout <<  << endl;
       cout << "OID: " << parmAid2 << endl;
       
       cout << "Выражение равно: " << amount = (poin1) * (poin2) << endl;
   }     

   void OperatorsLink::workAid(const int& parmAid1, const double& parmAid2) {
       
       
       string &link1 = "Значение1 :";
       
       string &link2 = "Значение2 : ";
       
       size_t &link3 = 1000;
       
       int sum = 4000;
       
       int amount1 = 0;
       
       double amount2 = 0;
       
       
       cout << "Сумма введенных Вами данных = " << amount2 = parmAid1 - parmAid2 << endl;
       
       cout << link1 << link1 << "По адрессу в памяти: " << &link1 << endl;
       cout << link2 << link2 << "По адрессу в памяти: " << &link2 << endl;
       cout << "Значение :" << link3 << "По адрессу в памяти: " << &link3 << endl; 
       
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
   
   
   
   