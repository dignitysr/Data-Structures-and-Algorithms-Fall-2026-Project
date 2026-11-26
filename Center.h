#pragma once
#include "ArrayStack.h"
#include "Car.h"
#include "UI.h"
#include "priQueue.h"
#include "Node.h"
#include"WashBay.h"
#include"ElecBay.h"
#include"MechBay.h"
#include"DiagBay.h"
#include"WAIT_MU.h"
#include"WAIT_WU.h"
#include"WAIT_EU.h"
#include"LATE_List.h"
#include"IDLE_List.h"
#include"ERLY_List.h"
#include"Statistics.h"
#include "DEFS.h"
#include <fstream>
#include <iomanip>

class Center
{
	float Pcancel;
	float Presc;

	int onTimeCount = 0;
	Statistics centerStatistics;
	PriorityQueue<Car*> serviceCars;
	ArrayStack<Car*> finishedCars;
	ArrayStack<Car*> cancelledCars;
	LinkedQueue<WashBay*> freeWUList;
	LinkedQueue<ElecBay*> freeEUList;
	LinkedQueue<MechBay*> freeMUList;
	LinkedQueue<DiagBay*> freeDUList;

	WaitWU washWaitingList;
	WaitMU mechWaitingList;
	WaitEU elecWaitingList;

	PriorityQueue<Car*> diagCars;
	LinkedQueue<Car*>  readyList;
	LATEList lateList;
	ERLYList earlyList;
	IDLEList idleList;

public:
	void loadFile();
	void saveStatistics(string fileName);

	void finishCar(Car* car, int currentTimestep);
	void cancelCar(Car* car, int currentTimestep);

	bool assignToWash(Car* car, int currentTimestep);
	bool assignToMech(Car* car, int currentTimestep);
	bool assignToElec(Car* car, int currentTimestep);
	bool assignToRandomBay(Car* car, int currentTimestep);
	
	int distributeIdleCars(int currentTimestep);
	void diagnoseCars(int currentTimestep);
	void handleEarlyCars(int currentTimestep, int distributedCars);
	void handleLateCars(int currentTimestep);
	// i hate me
	void Check_finished_Diagnosis_and_generate_the_service_list(int currentTimestep);
    bool car_to_its_next_service_waiting_list(Car* car, int currentTimestep);

	Car* handleCarAfterDiag(Car* car, int currentTimestep);

	bool ReadytoDiag(Car* car,int currentTimestep);
	bool assignServiceCar(Car* car, WaitMU mu,int currentTimestep);
	bool assignServiceCar(Car* car, WaitEU eu, int currentTimestep);
	bool assignServiceCar(Car* car, WaitWU wu, int currentTimestep);
	bool checkFinalService(Car* car, int currentTimestep);
	bool toFinishList(Car* car, int currentTimestep);

	bool runTestSimulation(int currentTimestep);
	bool runSimulation(int currentTimestep);
	void allocateBays(int count);
	void allocateNewBays(Bay* bay, int number, int cap = 1);
	void printAll(UI* X);
	void generateIdles();
};