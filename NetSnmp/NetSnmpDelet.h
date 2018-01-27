/*
 * Хидер содержащий перегруженный оператор operator(), для освобождения
 * "удаления" занимаемой области памяти, для реализации типа nique_ptr
 */

/* 
 * File:   NetSnmpDelet.h
 * Author: ruslan
 *
 * Created on 10 декабря 2017 г., 4:01
 */

#include<net-snmp/net-snmp-config.h>
#include<net-snmp/net-snmp-includes.h>
#include<string>
#include<memory>
using namespace std;


#ifndef NETSNMPDELET_H
#define NETSNMPDELET_H

class NetSnmpDelet {

public:
    
    void operator()(netsnmp_session *ses);


} ; // Конец Класса

#endif /* NETSNMPDELET_H */
