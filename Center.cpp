#include "Center.h"

void Center::loadFile() {
	int N_DU, N_MU, N_EU, N_WU, WB_Cap, M, VT, CID, PT, DD;
	ifstream InFile("input.txt");
	if (InFile.is_open()) {
		InFile >> N_DU;
		for (int i = 0;i < N_DU;i++) {
			DiagBay* dummy = new DiagBay();
			freeDUList.enqueue(dummy);
		}
		InFile >> N_MU;
		for (int i = 0;i < N_MU;i++) {
			MechBay* dummy = new MechBay();
			freeMUList.enqueue(dummy);
		}
		InFile >> N_EU;
		for (int i = 0;i < N_EU;i++) {
			ElecBay* dummy = new ElecBay();
			freeEUList.enqueue(dummy);
		}
		InFile >> N_WU;

		InFile >> WB_Cap;
		for (int i = 0;i < N_WU;i++) {
			WashBay* dummy = new WashBay(WB_Cap);
			freeWUList.enqueue(dummy);
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
			idleList.enqueue(dummy);
		}
	}
}