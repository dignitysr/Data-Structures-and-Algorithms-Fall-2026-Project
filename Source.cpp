#include "Center.h"
#include <iostream>

int main() {
	Center testCenter;


	int number;
	cout << "Type the number of the input file you would like to load 1-6" << endl;
	while (cin >> number && (number > 6 || number < 1)) {
		cout << "Please retype the number" << endl;
	}


	testCenter.loadFile("input" +to_string(number) +".txt");

	srand((uint16_t)time(nullptr));
	
	UI* ui = new UI;

	int timestep = 0;
	cout << "SilentMode ==> 1\nInteractiveMode==> 2" << endl;;
	while (cin >> number && (number != 2 && number != 1)) {
		cout << "Please retype the number" << endl;
	}
	if (number == 1) {
		while (testCenter.runSimulation(timestep)) {
			timestep++;
		}
	}
	if (number == 2) {
		while (testCenter.runSimulation(timestep)) {
			timestep++;
			testCenter.printAll(ui);
	        cout << timestep << endl;
	        ui->waitForInput();
		}
	}
	
	testCenter.getStatistics().setTotalSimulationTime(timestep);
	testCenter.printAll(ui);
	string filename;
	cout << "Enter your desired output file name" << endl;
	cin >> filename;
	testCenter.saveStatistics(filename);


}