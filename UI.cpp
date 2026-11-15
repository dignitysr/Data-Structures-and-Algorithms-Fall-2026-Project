#include "UI.h"

template <typename T>
    void UI<T>::printQueue(LinkedQueue<T> &Q)
{
		if (IDLEList* idle = dynamic_cast<IDLEList*>(&Q)) {

		}
		else if (LATEList* idle = dynamic_cast<LATEList*>(&Q)) {

		}
		else if (WaitEU* idle = dynamic_cast<WaitEU*>(&Q)) {

		}
		else if (WaitMU* idle = dynamic_cast<WaitMU*>(&Q)) {

		}
		else if (WaitWU* idle = dynamic_cast<WaitWU*>(&Q)) {

		}
		else if (Q.peek(T x) == DiagBay) {

		}
		else if (Q.peek(T x) == MechBay) {

		}
		else if (Q.peek(T x) == ElecBay) {

		}
		else if (Q.peek(T x) == WaitEU) {

		}
		else if (Q.peek(T x) == ) {

		}
}
template <typename T>
void UI<T>::printStack(ArrayStack<T> &S)
{
		
	}
template <typename T>
void UI<T>::printPriQueue(PriorityQueue<T> &P)
{
	
}
template <typename T>
int UI<T>::getint()
{
	cout << "Enter 1 for interactive mode or 2 for silent mode: "<<endl;
	int x;
	cin >> x;
	if (x != 1 || x != 0) {
		cout << "Please input either 1 or 2" << endl;
		cin >> x;
	}
	return x;
}
