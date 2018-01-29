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

        if(!ss.get()) {
                throw SnmpError("fail to open snmp_session");
        }
    }

    long NetSnmp::getInt(const string& aid) const {
        //По мотивам
        //http://www.net-snmp.org/tutorial/tutorial-5/toolkit/demoapp/index.html
        auto result = send(aid);

        for(variable_list * vars = result->variables; vars; vars = vars->next_variable) {
          if (vars->type == ASN_INTEGER)
              return *vars->val.integer;
        }
       
        throw SnmpError("fail to getInt");
    }

    string NetSnmp::getString(const string& aid) const {
        auto result = send(aid);
        
        for(variable_list * vars = result->variables; vars; vars = vars->next_variable) {
            if (vars->type == ASN_OCTET_STR) { // Проверка Условия
                
                // Создания строковой тпеременной "String" хранящая парараметры Область памяти библиотеки и кол-во байт
                string str(vars->val.string, vars->val_len);
                    
              return string(vars->val.string, vars->val_len);//Возвращает значения str  
                    
            }
        }
        
         
        
        }
        
        
        
        
        
        /*
         * Система сохраняет строковые вещи с типом ASN_OCTET_STR
         * Вот кусок из сишной доки, как они парсят строки
         *
         * Общая картина: когда библиотека послала команду, а железка ей в ответ прислала строку(например имя железки), то эта строка
         * хранится во внутренней памяти библиотеки, где-то там в кишках ее. Наша задача выделить у себя память
         * и в нашу память скопировать из кишков эту строку. И дальше уже работать с этой строкой у нас, в нашем коде.
         *
         *          //Проверяем, наш ли случай, если да, то попадем в тело ифа.
         *         if (vars->type == ASN_OCTET_STR) {
         *            malloc выделяет для тебя память. Это сишная тема.
         *             У него 1 параметр, числовой. Этот параметр - это количество байт, которые ты хочешь
         *              что бы он выделил для тебя. Его возвращаемое значение - это указатель, на выделеный кусок памяти.
         *
         * Вот тут они берут длину строки vars->val_len, прибавляют к ней 1 - видимо для  терминального нуля.
         * И полученное число идет аргументом в мэллок. Он возвращает указатель на эту память, который присваивают в sp
         *             char *sp = (char *)malloc(1 + vars->val_len);
         *
         *
         * Теперь идет вызов memcpy. Первый аргумент  у нее - это куда копируем, второй - откуда копируем и третий - сколько байт.
         * Они копируют в эту свежевыделенную память(в sp). Т.е. в нашу память.
         * Из vars->val.string - тут указатель на строку, которая библиотека получила в ответ и держит внутри себя.
         * vars->val_len - это длина ответа.

         *             memcpy(sp, vars->val.string, vars->val_len);
         *
         * Добавили терминальный нуль.
         *             sp[vars->val_len] = '\0';
         *                 printf("value #%d is a string: %s\n", count++, sp);  <----вывели строку
         *            освобоидили память данную мэллоком.
         *             free(sp);
         *         }
         *
         * Но это все сишная тема.
         *
         * Тебе надо сделать проще. У  нас есть в С++ класс, который называется std::string.
         * У него куча конструкторов, через которые можно создать строку и начинить полезной инфой.
         *
         * Среди этих конструкторов есть вот такой
         * string(const char* buf, size_t len);
         * Первый его параметр - это указатель на область памяти. А второй - количество байт, которые надо считать из этой памяти.
         *
         * Вот к примеру
         * Я создал массив из 4 символов.
         * char mas[] = {'A', 'B', 'C', 'D'}
         * Создаю строку, используя описанный выше коснтруктор
         * std::string str(mas, 4);
         *
         * cout << str << endl;
         *
         * Сиаут выведет мне строчку ABCD.
         *
         * Т.е. в str хранится строка "ABCD"
         *
         *
         * Теперь, прочитав все это, сделай такой-же if как у них в сишной теме, но в нем для считывания строки
         * из библиотечных кишков используй этот конструктор и создай строку и верни ее из этой функции.
         */
    
    std::unique_ptr<netsnmp_pdu, NetSnmpDeletPdu> NetSnmp::send(const string &aid) const {
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
        snmp_free_pdu(pdu);
    }
    
    void NetSnmpDelet::operator ()(netsnmp_session* ses) {
        snmp_close(ses);
    }
