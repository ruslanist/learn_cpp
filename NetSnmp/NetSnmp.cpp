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


    NetSnmp::NetSnmp(const string &net_ip, const string &net_community) {
       
        init_snmp("snmpapp");
        snmp_sess_init( &session);
        
        session.peername = (char*)ip.c_str();
        session.version = SNMP_VERSION_1;
        
        session.community = (u_char*)community.c_str();
        session.community_len = strlen((const char*) session.community);
        
        ss.reset(snmp_open(&session));
        // std::unique_ptr<struct snmp_session, NetSnmpDelet> ss(snmp_open(&session));
        
        
        if(!ss.get()) {
            
           
                    throw std::runtime_error("fail to open snmp_session");        
        }    
    }

    
    std::unique_ptr<snmp_pdu, NetSnmpDeletPdu> NetSnmp::send(const string &aid) const { 
        
        std::unique_ptr<snmp_pdu, NetSnmpDeletPdu> pdu(snmp_pdu_create(SNMP_MSG_GET));
       
        oid anOID[MAX_OID_LEN];
        size_t anOID_len = MAX_OID_LEN; 
        
     
        read_objid(aid.c_str(), anOID, &anOID_len);
        snmp_add_null_var(pdu.get(), anOID, anOID_len);
        std::unique_ptr<snmp_pdu, NetSnmpDeletPdu> response;
        
        snmp_pdu *temp =response.get();
        int status = snmp_synch_response(ss.get(), pdu.get(), &temp);
        
        
        if(status != STAT_SUCCESS || response.get()->errstat != SNMP_ERR_NOERROR) {
          
            return nullptr;
        }
    
    }
    
    
    void NetSnmpDeletPdu::operator () (snmp_pdu* netsnmp_pdu) { 
            
            snmp_free_pdu(netsnmp_pdu);
        }
    
    void NetSnmpDelet::operator ()(snmp_session* snmptr) {
    
       snmp_close(snmptr); 
    }