/*
 * Дополнительный Хидер для освобождения места для response.
 */

/* 
 * File:   NetSnmpDeletResponse.h
 * Author: ruslan
 *
 * Created on 5 января 2018 г., 2:44
 */

#ifndef NETSNMPDELETRESPONSE_H
#define NETSNMPDELETRESPONSE_H

#include<net-snmp/net-snmp-config.h>
#include<net-snmp/net-snmp-includes.h>
#include<string>
#include<memory>

class NetSnmpDeletResponse {

public:
    void operator () (snmp_pdu *netsnmp_response);
};






#endif /* NETSNMPDELETRESPONSE_H */

