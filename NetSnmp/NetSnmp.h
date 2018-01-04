/*
 * Заголовочный фаил содержащий Интерфес приложения  NetSnmp.
 */

/* 
 * File:   NetSnmp.h
 * Author: ruslan
 *
 * Created on 4 декабря 2017 г., 2:05
 */

#ifndef NETSNMP_H
#define NETSNMP_H

#endif /* NETSNMP_H */

#include<net-snmp/net-snmp-config.h>
#include<net-snmp/net-snmp-includes.h>
#include<string>
#include<memory>
#include"NetSnmpDelet.h"
#include "NetSnmpDeletPdu.h"

using std::string;

class NetSnmp {
        
        public:
                NetSnmp(string net_ip, string net_communiti);
                
                
                
                void send(string aid);
                
   

        private:
            struct snmp_session session;
            std::unique_ptr<struct snmp_session, NetSnmpDelet> ss;
            
            string ip;
            string community;
            


}; // Конец класса
