#pragma once
#include "ArrayStack.h"
#include "Car.h"
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
#include <fstream>

class UI
{
public:
	void printQueue(LinkedQueue<Car*> Q);
	void printQueue(LinkedQueue<MechBay*> Q);
	void printQueue(LinkedQueue<DiagBay*> Q);
	void printQueue(LinkedQueue<ElecBay*> Q);
	void printQueue(LinkedQueue<WashBay*> Q);


	void printStack(ArrayStack<Car*> S);
	void printPriQueue(PriorityQueue<Car*> P);

	int getint();
	void waitForInput();
};


