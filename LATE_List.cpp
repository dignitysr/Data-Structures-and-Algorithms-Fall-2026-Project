#include "LATE_List.h"

Car* LATEList::cancelRandomCar(int probability) {
	if (probability <= 0) return nullptr; //returns if there is no pCancel
	if (!frontPtr) return nullptr; //return if there is no cars late

	Node<Car*>* ptr = frontPtr;
	Car* selectedCar;
	while (ptr) {
		if (rand() % 100 < probability) {
			Node<Car*>* temp = ptr->getNext();
			if (!temp) { //checks if there is only one car or not
				dequeue(selectedCar); 
				return selectedCar;
			}
			ptr->setNext(temp->getNext());
			if (temp == backPtr) backPtr = ptr; //checks if we are at the last node
			selectedCar = temp->getItem();
			delete temp;
			return selectedCar;
		}
		ptr = ptr->getNext();
		
	}

	return nullptr;
}