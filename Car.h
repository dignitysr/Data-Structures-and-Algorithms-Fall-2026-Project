#pragma once
#include <iostream>
#include <string>
#include "LinkedQueue.h"
#include "DEFS.h"
#include "Service.h"
#include "ServiceList.h"
using namespace std;



class Car {
private:
    int ID;                        
    int PT;                        
    int VT;                        
    int DD;                         
    SequenceType seqType;           
    CarStatus status;     
    ServiceList srvlist;
    

                       

public:
    Car(int id, int pt, int vt, int dd = 3, SequenceType st = SS,CarStatus ss = STATUS_IDLE);
    ~Car();

   
    int getID() ;
    int getPT() ;
    int getVT() ;
    int getDD() ;
    SequenceType getSeqType();
    CarStatus getStatus();
    int GetTotalServiceTime();
    void insertService(Service& service);
    void removeservice();
   
    
    void setPT(int pt);
    void setVT(int vt);
    void setDD(int dd);
    void setSeqType(SequenceType st);
    void setStatus(CarStatus s);
  

  
   

   // for ui
    void print(ostream& os = cout) const;
    friend ostream& operator<<(ostream& os, const Car* c);
    friend ostream& operator<<(ostream& os, Car* c);
};

