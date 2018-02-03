/*
 * The Fail Implementations
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

OperatorsPointers::OperatorsPointers(const string &aid1, const string &nameAid1, const string descAid1, const string &aid2,  const string &nameAid2, const string descAid2, const string &infAid, const string &infMib, 
                                     const string &svitchname, const string &svitchIP, const string &svitchOS, const string &servername, const string &serverIP, const string &serverOS) {

    setoperatorAid1(aid1);
    setoperatorName1(nameAid1);
    setoperatordescAid1(descAid1);
    setoperatorAid2(aid2);
    setoperatorName2(nameAid2);
    setoperatordescAid2(descAid2);
    setoperatorinfAid(infAid);
    setoperatorinfMib(infMib);
    setswitchName(svitchname);
    setswitchIP(svitchIP);
    setswitchOS(svitchOS);
    setserverName(servername);
    setserverIP(serverIP);
    setserverOS(serverOS);

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
    
        
    void OperatorsBase::setoperatorinfAid(const string &infAid) {
        informAid = infAid;
    }
        string OperatorsBase::getoperatorinfAid() {
            return informAid;
        }
        
        
    void OperatorsBase::setoperatorinfMib(const string &infMib) {
        informMib = infMib;
    }
        string OperatorsBase::getoperatorinfMib() {
            return informMib;
        } 
        
        
    void OperatorsBase::setswitchName(const string &svitchname) {
        nameSwitch = svitchname;
    }
        string OperatorsBase::getswitchName() {
            return nameSwitch;
        }
        
        
    void OperatorsBase::setswitchIP(const string &svitchIP) {
        switchIp = svitchIP;
    }
        string OperatorsBase::getswitchIP() {
            return switchIp;
        }
        
        
    void OperatorsBase::setswitchOS(const string &svitchOS) {
        switchOS = svitchOS;
        }
        
        string OperatorsBase::getswitchOS() {
            return switchOS;
        }
        
        
    void OperatorsBase::setserverName(const string &servername) {
        nameServer = servername;
    }
        string OperatorsBase::getserverName() {
            return nameServer;
        }
        
        
   void OperatorsBase::setserverIP(const string &serverIP) {
        serverIp = serverIP;
   }
        string OperatorsBase::getserverIP() {
            return serverIp;
        }
        
    void OperatorsBase::setserverOS(const string &serverOs) {
        serverOS = serverOs;
    }
        string OperatorsBase::getserverOS() {
            return serverOS;
        }    
        
        
        void OperatorsPointers::aidInform() {
        
            cout << "В данном разделе меню Вы можете почитать информацию о протоколе Net-SNMP" << endl;
            
            cout << "Net-SNMP располагается на SourceForge, и, как правило, входит в топ-100 проектов рейтинговой системы SourceForge. В марте 2005 года он стал проектом месяца на SourceForge. Net-SNMP очень широко распространён и включен во многие операционные системы, включая большинство дистрибутивов Linux, FreeBSD, OpenBSD, Solaris и Mac OS X. Кроме того, его можно скачать на веб-сайте Net-SNMP." << endl;
        
            cout << "История: Стив Волдбюссер из CMU начал свободное распространение пакета программ SNMP в 1992 году. Пакет впоследствии был заброшен в CMU и Уэс Хардакер (Wes Hardaker) из UC Davis переименовал его в UCD-SNMP и расширил его для удовлетворения потребностей управления сетью электротехнического отдела проектирования. В конце концов мистер Хардакер покинул университет и понял, что этот проект в настоящее время используется в глобальной сети и, поэтому, переименовал его в Net-SNMP, чтобы отразить распределённость его разработки" << endl;
        }
        
        
        
OperatorsLink::OperatorsLink() {}

OperatorsLink::OperatorsLink(const string &aid1, const string &nameAid1, const string &aid2,  const string &nameAid2) {

}

OperatorsLink::OperatorsLink(const string &aid1, const string &nameAid1) {

}
    
   void OperatorsBase::operatoraidNameAll(const string& aid1, const string& nameAid1, const string& aid2, const string& nameAid2) {
    
        cout << "Названия (Идентифекатор): " << aid1 << " -" << "Значение OID: " 
                << nameAid1 << endl;
        
        cout << "Названия2 (Идентифекатор): " << aid2 << " -" << "Значение OID2: " 
                << nameAid2 << endl;        
                
    }

    void OperatorsBase::operatoraidName(const string& aid1, const string& nameAid1) {
    
        cout << "Названия (Идентифекатор): " << aid1 << " -" << "Значение OID: " 
                << nameAid1 << endl;
        
    }

   void OperatorsLink::aidInform() {
       
       int sum1 = 100;
       
       int sum2 = 200;
       
       int *poin1 = 0;
             
       int amout  = sum1 * sum2;
       
       *poin1 = amout;
       
       string Word1 = "Значение1 :";
       
       string Word2 = "Значение2 : "; 
       
      
       cout << Word1 << sum1 << "По адрессу в памяти: " << &sum1 << endl;
       cout << Word2 << sum2 << "По адрессу в памяти: " << &sum2 << endl;
       
       cout << "Cумма вычисления =" << Word1 << " + " << Word2 << " = " 
               << poin1 << endl;       
   }  
   
   
   
   OperatorsInformation::OperatorsInformation() {}
  
   void OperatorsInformation::aidInform() {
   
       cout << "OID (Object Identifier, идентификатор объекта) — это глобально уникальный номер, идентифицирующий объекты. Глобально-уникальный означает, что во всей вселенной существует единственная организация, отвечающая за определение объекта и его функциональность." << endl;
       
       cout << "Management Information Base (MIB, база управляющей информации) - виртуальная база данных, используемая для управления объектами в сети связи. Наиболее часто это понятие связывают с Simple Network Management Protocol (SNMP), но также оно используется в более широком смысле - в контексте модели управления сети OSI/ISO. Хотя термин MIB предназначен для обозначения всей доступной информации об объекте, он также часто используется для обозначения конкретного подмножества, которое правильнее называть MIB-модулем." << endl;
       
   }
   
   
   
   