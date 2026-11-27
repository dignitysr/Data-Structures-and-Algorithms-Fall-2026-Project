#include "Car.h"
#include "iostream"

Car::Car(int id, int pt, int vt, int dd, SequenceType st, CarStatus ss): ID(id), PT(pt), VT(vt), DD(dd), seqType(st), status(ss) 
{
    CT = -1;
    FT = -1;
    totalWaitingTime = 0;
    totalServiceTime = 0;
    countOnArrival = -1;
    waitingListInitialTimestep = 0;
}

Car::~Car() {
    Service* s;
    while (srvList.dequeue(s)) { 
    }
}

int Car::getID() {
    return ID;
}
int Car::getPT()  { 
    return PT; }
int Car::getVT() { 
    return VT;
}
int Car::getDD() { 
    return DD;
}
int Car::getFT() { 
    return FT;
}
int Car::getCT() { 
    return CT;
}
int Car::getCountOnArrival() { 
    return countOnArrival;
}
ServiceList& Car::getSrvList()
{
    return srvList;
}
Bay* Car::getBay() {
    return currentBay;
}
SequenceType Car::getSeqType() { 
    return seqType; }
CarStatus Car::getStatus() { return status;
}

int Car::getTotalServiceTime() const 
{
    return totalServiceTime;
}

void Car::insertService(Service* service)
{
    srvList.enqueue(service);
}

void Car::removeService()
{
    Service* s;
    if (seqType==SS) {
        srvList.dequeue(s);
    }
    else if (seqType == FS) {
        //later to be done!!
    }
}
void Car::generateRandomservices() {
    int numServices = (rand() % 3) + 1;
    int count = 0;
    Service* randomService;
    bool addedMU = false;
    bool addedEU = false;
    bool addedWU = false;
 
    seqType = (rand() % 2 == 0) ? FS : SS;

    while (count < numServices) {
        int r = rand() % 3;
  
        if (r == 0 && !addedMU) {
            int randomDuration = (rand() % 10 + 15);
            randomService = new Service(TYPE_MU, randomDuration);
            insertService(randomService);
            addedMU = true;
            count++;
        }
        else if (r == 1 && !addedEU) {
            int randomDuration = (rand() % 4 + 15);
            randomService = new Service(TYPE_EU, randomDuration);
            insertService(randomService);
            addedEU = true;
            count++;
        }
        else if (r == 2 && !addedWU) {
            int randomDuration = (rand() % 4 + 15);
            randomService = new Service(TYPE_WU, randomDuration);
            insertService(randomService);
            addedWU = true;
            count++;
        }
    }

}

void Car::setInitialTimestep(int currentTimestep)
{
    waitingListInitialTimestep = currentTimestep;
}

void Car::setTotalServicetime()
{
    totalServiceTime = srvList.getTotalServiceTime();
}

//hi



void Car::setPT(int pt) { 
    PT = pt; }
void Car::setVT(int vt) { VT = vt;
}
void Car::setDD(int dd) { DD = dd;
}
void Car::setCT(int ct) { CT = ct;
}
void Car::setFT(int ft) { FT = ft;
}
void Car::setCountOnArrival(int count) { countOnArrival = count;
}
void Car::setSeqType(SequenceType st) { seqType = st;
}
void Car::setStatus(CarStatus s) { status = s;
}
int Car::getTotalWaitingTime()
{
    return totalWaitingTime;
}
int Car::addTotalWaitingTime(int currentTimestep)
{
    int w = currentTimestep - waitingListInitialTimestep;
    totalWaitingTime += w;
    waitingListInitialTimestep = currentTimestep;
    return w;
}
void Car::print()
{
    cout << "Car ID is: " << getID();
    cout << "Car Appointment time is: " << getPT();
    cout << "Car Arrival time is: " << getVT();
    cout << "Car Diagnosis Duration is: " << getDD();
    switch (currentBay->getType()) {
    case DU:
        cout << "Car Bay is: Diagnosis Unit";
        break;
    case MU:
        cout << "Car Bay is: Mechanical Unit";
        break;
    case EU:
        cout << "Car Bay is: Electircal Unit";
        break;
    case WU:
        cout << "Car Bay is: Washing Unit";
        break;
   }
    switch (seqType) {
    case SS:
        cout << "Car Sequence type is: Strict Sequence";
        break;
    case FS:
        cout << "Car Sequence type is: Flexible Sequence";
        break;
    }
    switch (status) {
    case  STATUS_IDLE:
        cout << "Car Status is: Idle";
        break;
    case  STATUS_ERLY:
        cout << "Car Status is: Early";
        break;
    case STATUS_LATE:
        cout << "Car Status is: Late";
        break;
    case STATUS_REDY:
        cout << "Car Status is: Ready";
        break;
    case STATUS_DIAG:
        cout << "Car Status is: Diagnosing";
        break;
    case STATUS_WAIT:
        cout << "Car Status is: Waiting";
        break;
    case STATUS_SERV:
        cout << "Car Status is: In service";
        break;
    case STATUS_CNCL:
        cout << "Car Status is: Cancelled";
        break;
    case STATUS_FNSH:
        cout << "Car Status is: Finished";
        break;
    }
}
bool Car::operator==(const Car& other) const
{
    if (other.ID != ID || other.VT != VT || other.CT != CT || other.DD != DD || other.FT != FT || other.countOnArrival != countOnArrival ||  other.PT != PT|| other.totalWaitingTime!=totalWaitingTime) {
        return false;
    }
    else {
        return true;
    }
}
void Car::setBay(Bay* bay) { currentBay = bay;
}
ostream& operator<<(ostream& os,  const Car* c)
{
    switch (c->status) {
    case  STATUS_IDLE:
        cout << "[C" << c->ID << ", " << c->VT << ", " << c->PT << "] ";
        break;
    case  STATUS_ERLY:
        cout <<  "[C" << c->ID << ", " << c->VT << ", " << c->PT << "] ";
        break;
    case STATUS_LATE:
        cout <<"[C" << c->ID << ", " << c->VT << ", " << c->PT << "] ";
        break;
    case STATUS_REDY:
        cout <<  "[C" << c->ID << ", " << c->VT << ", " << c->PT << "] ";
        break;
    case STATUS_DIAG:
        cout <<  "[C" << c->ID << ", " << c->currentBay->getID() << "] ";
        break;
    case STATUS_WAIT:
        cout << "[C" << c->ID << ", " << c->getTotalServiceTime() << "] ";
        break;
    case STATUS_SERV:
        cout << "[C" << c->ID << ", " << c->currentBay->getID() << "] ";
        break;
    case STATUS_CNCL:
        cout << "[C" << c->ID << ", "<<c->CT << "] ";
        break;
    case STATUS_FNSH:
        cout << "[C" << c->ID << ", " << c->FT << "] ";
        break;
    }

    return os;
}
ostream& operator<<(ostream& os, Car* c)
{
    switch (c->status) {
    case  STATUS_IDLE:
        cout << "[C" << c->ID << ", " << c->VT << ", " << c->PT << "] ";
        break;
    case  STATUS_ERLY:
        cout <<  "[C" << c->ID << ", " << c->VT << ", " << c->PT << "] ";
        break;
    case STATUS_LATE:
        cout <<"[C" << c->ID << ", " << c->VT << ", " << c->PT << "] ";
        break;
    case STATUS_REDY:
        cout <<  "[C" << c->ID << ", " << c->VT << ", " << c->PT << "] ";
        break;
    case STATUS_DIAG:
        cout <<  "[C" << c->ID << ", " << c->currentBay->getID() << "] ";
        break;
    case STATUS_WAIT:
        cout << "[C" << c->ID << ", " << c->getTotalServiceTime() << "] ";
        break;
    case STATUS_SERV:
        cout << "[C" << c->ID << ", " << c->currentBay->getID() << "] ";
        break;
    case STATUS_CNCL:
        cout << "[C" << c->ID << ", "<<c->CT << "] ";
        break;
    case STATUS_FNSH:
        cout << "[C" << c->ID << ", " << c->FT << "] ";
        break;
    }

    return os;
}
