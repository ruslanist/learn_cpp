/*
 * TheBase Class Operating System
 */

/* 
 * File:   OperatorsBase.h
 * Author: ruslan
 *
 * Created on 30 января 2018 г., 20:14
 */

#ifndef OPERATORSBASE_H
#define OPERATORSBASE_H



#include <iostream>
#include <string>

using namespace std;

class OperatorsBase {
    
public:
        
        void setoperatorAid1(const string &);
        string getoperatorAid1();
               
        void setoperatorName1(const string &);
        string getoperatorName1();
        
        void setoperatordescAid1(const string &);
        string getoperatordescAid1();
        
        void setoperatorAid2(const string &);
        string getoperatorAid2();
        
        void setoperatorName2(const string &);
        string getoperatorName2();
        
        void setoperatordescAid2(const string &);
        string getoperatordescAid2();    
         
        void setoperatorinfAid(const string &);
        string getoperatorinfAid();
               
        void setoperatorinfMib(const string &);
        string getoperatorinfMib(); 
        
        void setswitchName(const string &);
        string getswitchName();
        
        void setswitchIP(const string &);
        string getswitchIP();
        
        void setswitchOS(const string &);
        string getswitchOS();
        
        void setserverName(const string &);
        string getserverName();
        
        void setserverIP(const string &);
        string getserverIP();
        
        void setserverOS(const string &);
        string getserverOS();
         
         
                
        void operatoraidName(const string &aid1, const string &nameAid1);
        
        void operatoraidNameAll(const string &aid1, const string &nameAid1, const string &aid2,  const string &nameAid2);
        
                
        virtual void aidInform() =0;
        
private:
    
    string fieldAid1;
    
    string fieldName1;

    string fieldAid2;
    
    string fieldName2;
    
    string descriptionAid1;
            
    string descriptionAid2; 
    
    string informAid;
    
    string informMib;
    
    string nameSwitch;
            
    string switchIp;
            
    string switchOS;
            
    string nameServer;
            
    string serverIp;
            
    string serverOS;
            
};



#endif /* OPERATORSBASE_H */

/*
 Данное предложение нужно модорнезировать:
 * 
 * 1) Приложение запускается, но с ошибками, в связи с этим нужно провести отладку программы
 * 
 * 2) При отладки обратить внимание на ввод string  в cin. Так как cin  не позволяет вводить текст с пробелами.
 *    В  связи с этим нужно поменять в main cin на getline(cin string a);
 * 
 * 3) Модернизироват приложение за счет Инциализации списком в конструкторе.
 * 
 * 4) Модорнезация за счет передачи параметров об.ектом и вызова нужного метода
 *    Пример - obj(string a, STRING B), далее вызов и передача параметров методу
 *    obj.metod();
 * 
 */