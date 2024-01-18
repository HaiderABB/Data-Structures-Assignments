#include <iostream>
#include <string>
using namespace std;
template <typename T>

class node {
	T person;
	node<T>* next;
public:
	node(const T & p = 0, node<T>* n = NULL) {
		person = p;
		next = n;
	}
	T getData() { return person; }
	void setData(const T&p){
		person = p;
	}
	node<T>* getNext() { return next; }
	void setNext(node<T>* n) { next = n; }
};
template <typename T>
class queue {
	int size;
	node<T>* rear;
	node<T>* front;
public:
	queue() {
		rear = NULL;
		front = NULL;
		size = 0;
	}
	queue(int n) // n is number of people
	{
		for (int i = 1;i <= n;i++)
			enqueue(i);
	}
	queue(const T* arr, int n)
	{
		for (int i = 0;i < n;i++)
			enqueue(arr[i]);
	}
	void enqueue(const T &  n ){
		if (size == 0)
		{
			rear = new node<T>(n);
			front = rear;
			size++;
		}
		else
		{
			rear->setNext(new node<T>(n));
			rear = rear->getNext();
			size++;
		}
	}
	T dequeue() {
		if (size == 1)
		{
			T temp = front->getData();
			delete front;
			front = rear = NULL;
			size--;
			return temp;
		}
		else if(size>1)
		{
			node<T>* temp = front;
			T tempD = front->getData();
			front = front->getNext();
			delete temp; 
			size--;
			return tempD;
		}
		else
		{
			cout << "Queue is empty , can't dequeue" << endl;
			return T();
		}
	}
	bool isEmpty() {
		return size == 0;
	}
	bool isSize1() {
		return size == 1;
	}
	T getRear() { return rear->getData(); }
	T getFront() { return front->getData(); }
	~queue()
	{
		while (!isEmpty())
			dequeue();
	}
};
