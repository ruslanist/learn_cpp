/*
 * Файл реализации проекта NetSnmp.
 */

/* 
 * File:   NetSnmp.cpp
 * Author: ruslan
 *
 * Created on 4 декабря 2017 г., 2:04
 */


#include <iostream>
#include "NetSnmp.h"
#include<string>
#include<memory>
#include"SnmpError.h"


using std::string;
using std::cout;
using std::endl;

     
    SnmpError::SnmpError(const string& err) : std::runtime_error(err) {}
    
    NetSnmp::NetSnmp(const string &net_ip, const string &net_community) {
       
        init_snmp("snmpapp");
        netsnmp_session session;
        snmp_sess_init( &session);
        
        session.peername = (char*)net_ip.c_str();
        session.version = SNMP_VERSION_2c;
        
        session.community = (u_char*)net_community.c_str();
        session.community_len = net_community.length();
        
        ss.reset(snmp_open(&session));

    }

    long NetSnmp::getInt(const string& aid) const {
        //По мотивам
        //http://www.net-snmp.org/tutorial/tutorial-5/toolkit/demoapp/index.html
        auto result = send(aid);
        
      
        
        
        if (result && result->variables && result->variables->type == ASN_INTEGER) { // Проверка Условия
            
              
              return *result->variables->val.integer;
                    
            }
       
        throw SnmpError("fail to getInt");
    }

    string NetSnmp::getString(const string& aid) const {
        auto result = send(aid);
        
            if (result && result->variables && result->variables->type == ASN_OCTET_STR) { // Проверка Условия
                    
              return string((const char*)result->variables->val.string, result->variables->val_len);
                    
            }
        
    }
           
    std::unique_ptr<snmp_pdu, NetSnmpDeletPdu> NetSnmp::send(const string &aid) const {
        //Похоже что мы не должны это освобождать
        netsnmp_pdu * pdu = snmp_pdu_create(SNMP_MSG_GET);
       
        oid anOID[MAX_OID_LEN];
        size_t anOID_len = MAX_OID_LEN; 
        
        read_objid(aid.c_str(), anOID, &anOID_len);
        snmp_add_null_var(pdu, anOID, anOID_len);
        
        netsnmp_pdu *temp = nullptr;

        int status = snmp_synch_response(ss.get(), pdu, &temp);
        std::unique_ptr<netsnmp_pdu, NetSnmpDeletPdu> response(temp);
        
        if(status != STAT_SUCCESS || response.get()->errstat != SNMP_ERR_NOERROR) {
            throw SnmpError("fail to send");
        }

        return response;
    }
    
    
    void NetSnmpDeletPdu::operator () (netsnmp_pdu* pdu) {
        //snmp_free_pdu(pdu);
    }
    
    void NetSnmpDelet::operator ()(netsnmp_session* ses) {
        //snmp_close(ses);
    }
