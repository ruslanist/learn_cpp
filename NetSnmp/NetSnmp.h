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

#include<net-snmp/net-snmp-config.h>
#include<net-snmp/net-snmp-includes.h>
#include<string>
#include<memory>
#include<stdexcept>
#include"NetSnmpDelet.h"
#include "NetSnmpDeletPdu.h"

using std::string;

class NetSnmp { 
        
        public:
                NetSnmp(const string &net_ip, const string &net_communiti);
                
                string getString(const string& aid) const;

                long getInt(const string& aid) const;

                std::unique_ptr<netsnmp_pdu, NetSnmpDeletPdu> send(const string &aid) const;
                  

        private:
            std::unique_ptr<netsnmp_session, NetSnmpDelet> ss;
}; // Конец класса


#endif /* NETSNMP_H */

