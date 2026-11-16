#pragma once
#include <iostream>
#include <string>
#include "LinkedQueue.h"
#include "DEFS.h"
#include "Service.h"
#include "ServiceList.h"
#include "Bay.h"
using namespace std;

class Car {
private:
    int ID;
    int PT;
    int VT;
    int DD;
    int CT;
    int FT;
    SequenceType seqType;           
    CarStatus status;     
    ServiceList srvList;
    Bay* currentBay;
    

public:
    Car(int id, int pt, int vt, int dd, SequenceType st = SS, CarStatus ss = STATUS_IDLE);
    ~Car();

   
    int getID();
    int getPT();
    int getVT();
    int getDD();
    int getFT();
    int getCT();
    Bay* getBay();
    SequenceType getSeqType();
    CarStatus getStatus();
    int getTotalServiceTime() ;
    void insertService(Service& service);
    void removeService();

    void setPT(int pt);
    void setVT(int vt);
    void setDD(int dd);
    void setFT(int ft);
    void setCT(int ct);
    void setBay(Bay* bay);
    void setSeqType(SequenceType st);
    void setStatus(CarStatus s);

    // for ui ya maro
    void print();
    friend ostream& operator<<(ostream& os, const Car* c);
    friend ostream& operator<<(ostream& os, Car* c);
};

