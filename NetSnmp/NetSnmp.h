/*
 * Заголовочный фаил содержащий Интерфес приложения  NetSnmp.
 */

/* 
 * File:   NetSnmp.h
 * Author: ruslan
 *
 * Created on 4 декабря 2017 г., 2:05
 */

#include<net-snmp/net-snmp-config.h>
#include<net-snmp/net-snmp-includes.h>
#include<string>
#include<memory>
#include<stdexcept>
#include"NetSnmpDelet.h"
#include "NetSnmpDeletPdu.h"

using std::string;

#ifndef NETSNMP_H
#define NETSNMP_H

class NetSnmp { 
        
        public:
                NetSnmp(const string &net_ip, const string &net_communiti);
                
               string getString(const string& aid); 
                
                std::unique_ptr<snmp_pdu, NetSnmpDeletPdu> send(const string &aid) const;
                
   

        private:
            snmp_session session;
            std::unique_ptr<snmp_session, NetSnmpDelet> ss;
            
            string ip;
            string community;
            
}; // Конец класса


#endif /* NETSNMP_H */

