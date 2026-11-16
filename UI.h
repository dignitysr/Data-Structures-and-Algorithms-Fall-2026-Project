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
	template <typename T>
	void printQueue(LinkedQueue<T> &Q);
	template <typename T>
	void printStack(ArrayStack<T> &S);
	template <typename T>
	void printPriQueue(PriorityQueue<T> &P);
	int getint();
	void waitForInput();
};


