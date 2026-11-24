#include "Statistics.h"

Statistics::Statistics()
{
    totalSimulationTime = 0;
    totalCars = 0;
    totalServiceTime = 0;
    FSTotalWaitingCount = 0;
    SSTotalWaitingCount = 0;
    MBCount = 0;
    WBCount = 0;
    EBCount = 0;
    DBCount = 0;

    cancellationCount = 0;
    reschedulingCount = 0;

    FScount = 0;
    SScount = 0;
}

void Statistics::addWaitingTime(Car* car, int time)
{
    SequenceType type = car->getSeqType();
    if (type == FS) {
        FSTotalWaitingCount += time;
    }
    else if (type == SS) {
        SSTotalWaitingCount += time;
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
void Statistics::incrementTypeCount(Car * car)
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

void Statistics::incrementBayCount(Bay* bay)
{
    if (dynamic_cast<MechBay*>(bay)) MBCount++;
    else if (dynamic_cast<WashBay*>(bay)) WBCount++;
    else if (dynamic_cast<ElecBay*>(bay)) EBCount++;
}


void Statistics::incrementCancellationCount()
{
    cancellationCount++;
}



