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
    int totalWaitingTime;
    
    int countOnArrival; // for late cars

public:
    Car(int id, int pt, int vt, int dd, SequenceType st = NS, CarStatus ss = STATUS_IDLE);
    ~Car();

   
    int getID();
    int getPT();
    int getVT();
    int getDD();
    int getFT();
    int getCT();
    int getCountOnArrival();
    ServiceList getSrvList();
    Bay* getBay();
    SequenceType getSeqType();
    CarStatus getStatus();
    int getTotalServiceTime() const;
    void insertService(Service* service);
    void removeService();
    void generateRandomservices();

    void setPT(int pt);
    void setVT(int vt);
    void setDD(int dd);
    void setFT(int ft);
    void setCT(int ct);
    void setCountOnArrival(int count);
    void setBay(Bay* bay);
    void setSeqType(SequenceType st);
    void setStatus(CarStatus s);
    int getTotalWaitingTime();
    void addTotalWaitingTime(int time);
    // for ui ya maro
    void print();
    bool operator==(const Car& other) const;
    friend ostream& operator<<(ostream& os, const Car* c);
    friend ostream& operator<<(ostream& os, Car* c);
};

