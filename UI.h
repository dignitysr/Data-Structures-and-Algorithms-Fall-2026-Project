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
template <typename T>
class UI
{
	void printQueue(LinkedQueue <T>&Q);
	void printStack(ArrayStack <T>&S);
	void printPriQueue(PriorityQueue <T> &P);
	int getint();
};


