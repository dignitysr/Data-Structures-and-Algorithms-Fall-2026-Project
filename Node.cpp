#include "Node.h"
template < typename T>
Node<T>::Node()
{
	next = nullptr;
}

template < typename T>
Node<T>::Node(const T& r_Item)
{
	item = r_Item;
	next = nullptr;
}

template < typename T>
Node<T>::Node(const T& r_Item, Node<T>* nextNodePtr)
{
	item = r_Item;
	next = nextNodePtr;
}
template < typename T>
void Node<T>::setItem(const T& r_Item)
{
	item = r_Item;
}

template < typename T>
void Node<T>::setNext(Node<T>* nextNodePtr)
{
	next = nextNodePtr;
}

template < typename T>
T Node<T>::getItem() const
{
	return item;
}

template < typename T>
Node<T>* Node<T>::getNext() const
{
	return next;
}

#include "Service.h"
class Car;
class MechBay;
class WashBay;
class ElecBay;
class DiagBay;

template class Node<Car*>;
template class Node<Service>;
template class Node<MechBay*>;
template class Node<WashBay*>;
template class Node<ElecBay*>;
template class Node<DiagBay*>;
