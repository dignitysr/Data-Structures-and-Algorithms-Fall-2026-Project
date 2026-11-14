#pragma once
	template < typename T>
	class Node
	{
	private:
		T item; // A data item
		Node<T>* next; // Pointer to next node
	public:
		Node();
		Node(const T& r_Item);
		Node(const T& r_Item, Node<T>* nextNodePtr);
		void setItem(const T& r_Item);
		void setNext(Node<T>* nextNodePtr);
		T getItem() const;
		Node<T>* getNext() const;
	}; // end Node

