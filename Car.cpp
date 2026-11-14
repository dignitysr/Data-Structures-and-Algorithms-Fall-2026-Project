#include "Car.h"
#include "iostream"

Car::Car(int id, int pt, int vt, int dd, SequenceType st, CarStatus ss)
    : ID(id), PT(pt), VT(vt), DD(dd), seqType(st),
    status(ss){
}

Car::~Car() {
    Service s;
    while (srvlist.dequeue(s)) { 
    }
}

int Car::getID() {
    return ID;
}
int Car::getPT()  { 
    return PT; }
int Car::getVT() { return VT;
}
int Car::getDD() { 
    return DD;
}
SequenceType Car::getSeqType() { 
    return seqType; }
CarStatus Car::getStatus() { return status;
}

int Car::GetTotalServiceTime()
{
    return srvlist.GetTotalServiceTime();
}

void Car::insertService(Service& service)
{
    srvlist.enqueue(service);
}

void Car::removeservice()
{
    Service s;
    if (seqType==SS) {
        srvlist.dequeue(s);
    }
    else if (seqType == FS) {
        //later to be done!!
    }
}




void Car::setPT(int pt) { 
    PT = pt; }
void Car::setVT(int vt) { VT = vt;
}
void Car::setDD(int dd) { DD = dd;
}
void Car::setSeqType(SequenceType st) { seqType = st;
}
void Car::setStatus(CarStatus s) { status = s;
}







