#include "Center.h"
#include <iostream>

int main() {
	Center testCenter;

	// randomly generating 1000 cars for the IDLE list
	testCenter.loadFile();

	srand((uint16_t)time(nullptr));
	
	UI* ui = new UI;

	int timestep = 0;
	while (testCenter.runSimulation(timestep)) {
		timestep++;
	
		
	}
	
	testCenter.getStatistics().setTotalSimulationTime(timestep);
	testCenter.printAll(ui);
	cout << testCenter.getStatistics().getTotalWaitingTime();
	
	string filename;
	cout << "name";
	cin >> filename;
	testCenter.saveStatistics(filename);
}