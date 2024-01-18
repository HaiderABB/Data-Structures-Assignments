#include<iostream>
#include<string>
#include<string.h>
using namespace std;
template<typename string>
class Queue {
private:
	class Node {
		Node* next;
		string data;
	public:
		Node(string d)
		{
			next = nullptr;
			data = d;
		}
		string getData()
		{
			return data;
		}
		void setNext(Node* next)
		{
			this->next = next;
		}
		Node* getNext()
		{
			return next;
		}
		~Node()
		{

		}
	};
	Node* front;
	Node* rear;
public:
	Queue()
	{
		front = nullptr;
		rear = nullptr;
	}
	void Enqueue(string i)
	{
		if (front == nullptr)
		{
			Node* newNode = new Node(i);
			front = newNode;
			rear = newNode;
			newNode->setNext(nullptr);
		}
		else
		{
			Node* newNode = new Node(i);
			rear->setNext(newNode);
			rear = newNode;
			newNode->setNext(nullptr);
		}
	}
	string Dequeue()
	{
		string data;
		if (front == rear)
		{
			data = front->getData();
			delete rear;
			rear = nullptr;
			front = nullptr;
		}
		else
		{
			data = front->getData();
			Node* temp = front;
			front = front->getNext();
			delete temp;
			temp = nullptr;
		}
		return data;
	}
	bool isEmpty()
	{
		if (front == nullptr)
			return true;
		else
			return false;
	}
};

int indexReturn(char&c)
{
	int index = static_cast<int>(c);
	index = index - 97;
	return index;
}

void RadixSort(int m,int k , Queue<string>&mainQ)
{
	Queue<string>* q = new Queue<string>[m];
	char p;
	string n;
	int index;
	for (int i = k; i>0; --i)
	{
		while (!mainQ.isEmpty())
		{
			n = mainQ.Dequeue();
			p = n[i - 1];
			index = indexReturn(p);
			q[index].Enqueue(n);
		}
		for (int j = 0; j < m; ++j)
		{
			while (!q[j].isEmpty())
			{
				mainQ.Enqueue(q[j].Dequeue());
			}
		}
	}

	cout << "After runnign Radix sort" << endl;
	while (!mainQ.isEmpty())
	{
		cout << mainQ.Dequeue() << endl;
	}
}

int main()
{
	int m, k;
	m = 26;
	cout << "Enter k" << endl;
	cin >> k;

	Queue<string>mainQ;
	mainQ.Enqueue("abc");
	mainQ.Enqueue("def");
	mainQ.Enqueue("ghi");
	mainQ.Enqueue("xlv");
	mainQ.Enqueue("ntu");
	mainQ.Enqueue("pqz");
	mainQ.Enqueue("mng");
	mainQ.Enqueue("lou");
	RadixSort(m, k, mainQ);
}