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

using std::string;
using std::cout;
using std::endl;


    NetSnmp::NetSnmp(string ip, string community) {

        init_snmp("snmpapp");
        snmp_sess_init( &session);
        
        session.peername = (char*)ip.c_str();
        session.version = SNMP_VERSION_1;
        
        session.community = (u_char*)community.c_str();
        session.community_len = strlen((const char*) session.community);
        
        ss.reset(snmp_open(&session));
        // std::unique_ptr<struct snmp_session, NetSnmpDelet> ss(snmp_open(&session));
        
        
        if(!ss.get()) {
            
           
                    throw std::std::runtime_error("fail to open snmp_session");        
        }    
    }

    
    void NetSnmp::send(string aid) { 
    
        struct snmp_pdu *pdu = snmp_pdu_create(SNMP_MSG_GET);
        oid anOID[MAX_OID_LEN];
        size_t anOID_len = MAX_OID_LEN; 
        
     
        read_objid(aid.c_str(), anOID, &anOID_len);
        snmp_add_null_var(pdu, anOID, anOID_len);
        struct snmp_pdu *response = nullptr;
        int status = snmp_synch_response(ss.get(), pdu, &response);
        
        if(response) {
            
            snmp_free_pdu(response);
        }
    
    }
    
    void NetSnmpDelet::operator ()(snmp_session* snmptr) {
    
    
    }