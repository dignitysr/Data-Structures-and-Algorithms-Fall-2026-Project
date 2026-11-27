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
	int NSTotalWaitingTime;
	//Totalservicetime of all cars combined
	int totalServiceTime;
	//Bay Utilization 
	int MBUtilization;
	int WBUtilization;
	int EBUtilization;	
	int DBUtilization;
	//Bay Count 
	int MBCount;
	int WBCount;
	int EBCount;
	int DBCount;
	//Rate of cancellation/Resche/finish.
	int finishedCount;
	int cancellationCount;
	int reschedulingCount;
	//number of cars based on their SeqType
	int FScount;	
	int SScount;
	int totalBayCount;
public:
	Statistics();
	void addTotalWaitingTime(Car * car,int time); //adds the totalwaitingtime of ALL the cars combined (you must also use addtotalwaitingtime func in Car besides it) #Called between ready and diabay also between waitinglist and bay 
	void setTotalSimulationTime(int time); //Call it at the end of the simulation #Probably Called in Main
	void setTotalCars(int cars); //setter for the number of the total cars in idle #DO NOT CALL
	void incrementTotalCars(); //inc the number of total cars (useless) #DO NOT CALL
	void addTotalServiceTime(int time); //adds the totalservicetime of ALL the cars combined (Hint use func gettotalservicetime in Car class) #CALLED AFTER DIAG AFTER CHECKING THAT IT WONT CANCEL
	void addBayUtilization(Bay* bay,Service* service,Car* car);   //inc the time used of the type of bay used #IS CALLED AFTER DEQUEUING THER SERVICE FROM THE SERVICE LIST BEFORE ASSINGING THE CAR TO BAY 
	void incrementCancellationCount(); //inc the count of the cancelled cars #COULD BE CALLED IN LATE AND AFTER DIAG
	void incrementReschedulingCount(); //inc the count of the rescheduled cars #COULD BE CALLED IN EARLY
	void incrementFinishedCount();
	void incrementSeqTypeCount(Car * car); //inc the count of seqtype of each car (FS OR SS) #CALL AFTER DIAGNOSIS 
	void addTotalBayCount(Bay* bay, int count);
	
	//GETTERS
	int getMBCount()const;
	int getEBCount()const;
	int getDBCount()const;
	int getWBCount()const;
	int getTotalSimulationTime() const; 
	int getTotalCars() const;
	int getNSTotalWaitingTime() const;
	int getFSTotalWaitingTime() const;
	int getSSTotalWaitingTime() const;
	int getTotalWaitingTime() const;
	int getTotalServiceTime() const;
	int getMBUtilization() const;
	int getWBUtilization() const;
	int getEBUtilization() const;
	int getDBUtilization() const;
	int getFinishedCount() const;
	int getCancellationCount() const;
	int getReschedulingCount() const;
	int getFScount() const;
	int getSScount() const;

};

