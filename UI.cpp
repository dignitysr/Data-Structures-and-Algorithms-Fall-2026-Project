#include "UI.h"

template <typename T>
    void UI<T>::printQueue(LinkedQueue<T> &Q)
{
	
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
