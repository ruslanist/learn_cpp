/*
 * Файл служиший для удаления значения указателя pdu
 */

/* 
 * File:   NetSnmpDeletPdu.h
 * Author: ruslan
 *
 * Created on 4 января 2018 г., 19:59
 */

#ifndef NETSNMPDELETPDU_H
#define NETSNMPDELETPDU_H

#include<net-snmp/net-snmp-config.h>
#include<net-snmp/net-snmp-includes.h>
#include<string>
#include<memory>

using namespace std;


class NetSnmpDeletPdu {

public:
    void operator()(netsnmp_pdu *pdu);
    
};

#endif /* NETSNMPDELETPDU_H */
