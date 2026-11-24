#include "Statistics.h"

Statistics::Statistics()
{
    totalSimulationTime = 0;
    totalCars = 0;
    totalServiceTime = 0;
    FSTotalWaitingTime = 0;
    SSTotalWaitingTime = 0;
    NSTotalWaitingTime = 0;
    MBUtilization = 0;
    WBUtilization = 0;
    EBUtilization = 0;
    DBUtilization = 0;

    cancellationCount = 0;
    reschedulingCount = 0;

    FScount = 0;
    SScount = 0;
    totalBayCount = 0;
}

void Statistics::addTotalWaitingTime(Car* car, int time)
{
    car->addTotalWaitingTime(time);
    SequenceType type = car->getSeqType();
    if (type == FS) {
        FSTotalWaitingTime += time;
    }
    else if (type == SS) {
        SSTotalWaitingTime += time;
    }
    else if (type == NS) {
        NSTotalWaitingTime += time;
    }
}

void Statistics::setTotalSimulationTime(int time)
{
    totalSimulationTime = time;
}
void Statistics::setTotalCars(int cars)
{
    totalCars = cars;
}
void Statistics::incrementReschedulingCount()
{
    reschedulingCount++;
}
void Statistics::incrementSeqTypeCount(Car * car)
{
    SequenceType type = car->getSeqType();
    if (type == FS) {
        FScount++;
    }
    else if (type == SS) {
        SScount++;
    }
}
void Statistics::incrementTotalCars()
{
    totalCars++;
}



void Statistics::addTotalServiceTime(int time)
{
    totalServiceTime += time;
}

void Statistics::addBayUtilization(Bay* bay,Service* service,Car*car)
{
    if (dynamic_cast<MechBay*>(bay)) MBUtilization += service->getDuration();
    else if (dynamic_cast<WashBay*>(bay)) WBUtilization += service->getDuration();
    else if (dynamic_cast<ElecBay*>(bay)) EBUtilization += service->getDuration();
    else if (dynamic_cast<DiagBay*>(bay)) DBUtilization += car->getDD();
}
void Statistics::incrementCancellationCount()
{
    cancellationCount++;
}

int Statistics::getTotalSimulationTime() const
{
    return totalSimulationTime;
}

int Statistics::getTotalCars() const
{
    return totalCars;
}

int Statistics::getNSTotalWaitingTime() const
{
    return NSTotalWaitingTime;
}

int Statistics::getFSTotalWaitingTime() const
{
    return FSTotalWaitingTime;
}

int Statistics::getSSTotalWaitingTime() const
{
    return SSTotalWaitingTime;
}

int Statistics::getTotalWaitingTime() const
{
    return NSTotalWaitingTime+FSTotalWaitingTime+SSTotalWaitingTime;
}

int Statistics::getTotalServiceTime() const
{
    return totalServiceTime;
}

int Statistics::getMBUtilization() const
{
    return MBUtilization;
}

int Statistics::getWBUtilization() const
{
    return WBUtilization;
}

int Statistics::getEBUtilization() const
{
    return EBUtilization;
}

int Statistics::getDBUtilization() const
{
    return DBUtilization;
}

int Statistics::getCancellationCount() const
{
    return cancellationCount;
}

int Statistics::getReschedulingCount() const
{
    return reschedulingCount;
}

int Statistics::getFScount() const
{
    return FScount;
}

int Statistics::getSScount() const
{
    return SScount;
}



