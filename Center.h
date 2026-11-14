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

class Center
{
	priQueue<Car*>  InServ_cars;
	ArrayStack<Car*> finished_cars  ;
	ArrayStack<Car*> canclled_cars ;
	LinkedQueue<WashBay*> Free_WU_List;
	LinkedQueue<ElecBay*> Free_EU_List;
	LinkedQueue<MechBay*> Free_MU_List;
	LinkedQueue<DiagBay*> Free_DU_List;

	WAIT_WU waitwash;
	WAIT_MU waitmech;
	WAIT_EU waitelec;

	priQueue<Car*> DIAG_Cars;
	LinkedQueue<Car*>  REDY_cars;
	LATE_List  late_list;
	ERLY_List  early_list;
	IDLE_List  idle_list;

			
};