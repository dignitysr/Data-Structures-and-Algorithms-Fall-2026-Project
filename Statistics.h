#pragma once
#include "Car.h"
#include "Bay.h"
#include "MechBay.h"
#include "ElecBay.h"
#include "WashBay.h"
class Statistics
{
	int totalSimulationTime;
	int totalCars;
	int FSTotalWaitingCount;
	int SSTotalWaitingCount;
	int totalServiceTime;
	int MBCount;
	int WBCount;
	int EBCount;
	int DBCount;
	int cancellationCount;
	int reschedulingCount;
	int FScount;
	int SScount;
public:
	Statistics();
	void addWaitingTime(Car * car,int time);
	void setTotalSimulationTime(int time);
	void setTotalCars(int cars);
	void incrementTotalCars();
	void addTotalServiceTime(int time);
	void incrementBayCount(Bay* bay);
	void incrementCancellationCount();
	void incrementReschedulingCount();
	void incrementTypeCount(Car * car);

};

