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
#include "DEFS.h"
#include <fstream>

class Center
{
	float Pcancel;
	float Presc;

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

	void finishCar(Car* car, int currentTimestep);
	void cancelCar(Car* car, int currentTimestep);

	bool assignToWash(Car* car, int currentTimestep);
	bool assignToMech(Car* car, int currentTimestep);
	bool assignToElec(Car* car, int currentTimestep);
	bool assignToRandomBay(Car* car, int currentTimestep);
	
	bool runTestSimulation(int currentTimestep);
	void allocateBays(int count);
	void printall(UI* X);
	void generateIdles();
};