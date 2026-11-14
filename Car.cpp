#include "Car.h"


Car::Car(int id, int pt, int vt, int dd, SequenceType st)
    : ID(id), PT(pt), VT(vt), DD(dd), seqType(st),
    status(STATUS_IDLE){
}

Car::~Car() {
    Service* s = nullptr;
    while (srvList.dequeue(s)) {
        delete s;
    }
}

int Car::getID() { return ID; }
int Car::getPT()  { return PT; }
int Car::getVT() { return VT; }
int Car::getDD() { return DD; }
SequenceType Car::getSeqType() { return seqType; }
CarStatus Car::getStatus() { return status; }


void Car::setPT(int pt) { PT = pt; }
void Car::setVT(int vt) { VT = vt; }
void Car::setDD(int dd) { DD = dd; }
void Car::setSeqType(SequenceType st) { seqType = st; }
void Car::setStatus(CarStatus s) { status = s; }





