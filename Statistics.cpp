#include "Statistics.h"

Statistics::Statistics()
{
    totalSimulationTime = 0;
    totalCars = 0;
    totalWaitingTime = 0;
    totalServiceTime = 0;

    MBCount = 0;
    WBCount = 0;
    EBCount = 0;
    DBCount = 0;

    cancellationCount = 0;
    reschedulingCount = 0;

    FScount = 0;
    SScount = 0;
}

void Statistics::setTotalSimulationTime(int time)
{
    totalSimulationTime = time;
}
void Statistics::incrementTotalCars()
{
    totalCars++;
}

void Statistics::addTotalWaitingTime(int time)
{
    totalWaitingTime += time;
}

void Statistics::addTotalServiceTime(int time)
{
    totalServiceTime += time;
}

void Statistics::incrementMBCount()
{
    MBCount++;
}

void Statistics::incrementWBCount()
{
    WBCount++;
}

void Statistics::incrementEBCount()
{
    EBCount++;
}

void Statistics::incrementDBCount()
{
    DBCount++;
}

void Statistics::incrementCancellationCount()
{
    cancellationCount++;
}

void Statistics::incrementFScount()
{
    FScount++;
}

void Statistics::incrementSScount()
{
    SScount++;
}

