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

class Center
{
	float Pcancel;
	float Presc;
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
public:
	void loadfile() {
		int N_DU, N_MU, N_EU, N_WU, WB_Cap, M, VT, CID, PT, DD;
		ifstream InFile("input.txt");
		if (InFile.is_open()) {
			InFile >> N_DU;
			for (int i = 0;i < N_DU;i++) {
				DiagBay* dummy = new DiagBay();
				Free_DU_List.enqueue(dummy);
			}
			InFile >> N_MU;
			for (int i = 0;i < N_MU;i++) {
				MechBay* dummy = new MechBay();
				Free_MU_List.enqueue(dummy);
			}
			InFile >> N_EU;
			for (int i = 0;i < N_EU;i++) {
				ElecBay* dummy = new ElecBay();
				Free_EU_List.enqueue(dummy);
			}
			InFile >> N_WU;
			
			InFile >> WB_Cap;
			for (int i = 0;i < N_WU;i++) {
				WashBay* dummy = new WashBay(WB_Cap);
				Free_WU_List.enqueue(dummy);
			}
			InFile >> Pcancel;
			InFile >> Presc;
			
			InFile >> M;
			for (int i = 0;i < M;i++)
			{
				InFile >> VT;
				InFile >> CID;
				InFile >> PT;
				InFile >> DD;
				Car* dummy = new Car(CID, PT, VT, DD);
				idle_list.enqueue(dummy);
			}
			
		}
	}

			
};