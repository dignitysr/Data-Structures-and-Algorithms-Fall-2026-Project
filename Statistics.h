#pragma once
class Statistics
{
	int totalSimulationTime;
	int totalCars;
	int totalWaitingTime;
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
	void setTotalSimulationTime(int time);
	void incrementTotalCars();
	void addTotalWaitingTime(int time);
	void addTotalServiceTime(int time);
	void incrementMBCount();
	void incrementWBCount();
	void incrementEBCount();
	void incrementDBCount();
	void incrementCancellationCount();
	void incrementReschedulingCount();
	void incrementFScount();
	void incrementSScount();

};

