#pragma once
#include "Car.h"
#include "Bay.h"
#include "MechBay.h"
#include "ElecBay.h"
#include "WashBay.h"
#include "DiagBay.h"
class Statistics
{
	int totalSimulationTime;
	//total number of cars
	int totalCars;
	//Totalwaitingtime of all cars combined based on their seqtype
	int FSTotalWaitingTime;
	int SSTotalWaitingTime;
	//Totalservicetime of all cars combined
	int totalServiceTime;
	//Bay Utilization Count
	int MBUtilization;
	int WBUtilization;
	int EBUtilization;
	int DBUtilization;
	//Rate of cancellation/Resche.
	int cancellationCount;
	int reschedulingCount;
	//number of cars based on their SeqType
	int FScount;	
	int SScount;
	int totalBayCount;
public:
	Statistics();
	void addTotalWaitingTime(Car * car,int time); //adds the totalwaitingtime of ALL the cars combined (you must also use addtotalwaitingtime func in Car besides it) #Called between waitinglist and bay ig?
	void setTotalSimulationTime(int time); //Call it at the end of the simulation #Probably Called in Main
	void setTotalCars(int cars); //setter for the number of the total cars in idle #DO NOT CALL
	void incrementTotalCars(); //inc the number of total cars (useless) #DO NOT CALL
	void addTotalServiceTime(int time); //adds the totalservicetime of ALL the cars combined (Hint use func gettotalservicetime in Car class) #CALLED AFTER DIAG
	void addBayUtilization(Bay* bay,Service* service);   //inc the count of the type of bay used #IS CALLED AFTER EACH DEQUEUING FROM WAITINGLIST
	void incrementCancellationCount(); //inc the count of the cancelled cars #COULD BE CALLED IN LATE AND AFTER DIAG
	void incrementReschedulingCount(); //inc the count of the rescheduled cars #COULD BE CALLED IN EARLY
	void incrementSeqTypeCount(Car * car); //inc the count of seqtype of each car (FS OR SS) #CALL AFTER DIAGNOSIS 
	void addTotalBayCount(int count);
	//GETTERS
	int getTotalSimulationTime() const; 
	int getTotalCars() const;
	int getFSTotalWaitingTime() const;
	int getSSTotalWaitingTime() const;
	int getTotalServiceTime() const;
	int getMBUtilization() const;
	int getWBUtilization() const;
	int getEBUtilization() const;
	int getDBUtilization() const;
	int getCancellationCount() const;
	int getReschedulingCount() const;
	int getFScount() const;
	int getSScount() const;

};

