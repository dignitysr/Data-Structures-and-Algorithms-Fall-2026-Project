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
	void addWaitingTime(Car * car,int time); //adds the totalwaitingtime of ALL the cars combined (you must also use addtotalwaitingtime func in Car besides it) #Called between waitinglist and bay ig?
	void setTotalSimulationTime(int time); //Call it at the end of the simulation #Probably Called in Main
	void setTotalCars(int cars); //setter for the number of the total cars in idle #DO NOT CALL
	void incrementTotalCars(); //inc the number of total cars (useless) #DO NOT CALL
	void addTotalServiceTime(int time); //adds the totalservicetime of ALL the cars combined (Hint use func gettotalservicetime in Car class) #CALLED AFTER DIAG
	void incrementBayCount(Bay* bay);   //inc the count of the type of bay used #IS CALLED AFTER EACH DEQUEUING FROM WAITINGLIST
	void incrementCancellationCount(); //inc the count of the cancelled cars #COULD BE CALLED IN LATE AND AFTER DIAG
	void incrementReschedulingCount(); //inc the count of the rescheduled cars #COULD BE CALLED IN EARLY
	void incrementTypeCount(Car * car); //inc the count of seqtype of each car (FS OR SS) #CALL AFTER DIAGNOSIS 
	//GETTERS
	int getTotalSimulationTime() const; 
	int getTotalCars() const;
	int getFSTotalWaitingCount() const;
	int getSSTotalWaitingCount() const;
	int getTotalServiceTime() const;
	int getMBCount() const;
	int getWBCount() const;
	int getEBCount() const;
	int getDBCount() const;
	int getCancellationCount() const;
	int getReschedulingCount() const;
	int getFScount() const;
	int getSScount() const;

};

