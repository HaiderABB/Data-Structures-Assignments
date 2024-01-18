#include<iostream>
using namespace std;
#include<iostream>
using namespace std;

class Queue {
private:
	class Node {
		Node* next;
		int age, items;
	public:
		Node(int age, int items)
		{
			next = nullptr;
			this->age = age;
			this->items = items;
		}
		int getAge()
		{
			return age;
		}
		int getItems()
		{
			return items;
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
	
public:
	Node* front;
	Node* rear;
	int qSize = 0;
	Queue()
	{
		front = nullptr;
		rear = nullptr;
	}
	void Enqueue(int age,int items)
	{
		if (front == nullptr)
		{
			Node* newNode = new Node(age,items);
			front = newNode;
			rear = newNode;
			newNode->setNext(nullptr);
		}
		else
		{
			Node* newNode = new Node(age,items);
			rear->setNext(newNode);
			rear = newNode;
			newNode->setNext(nullptr);
		}
		++qSize;
	}
	
	void Dequeue(int&age,int&items)
	{
				int data;
				if (front == rear)
				{
					age = front->getAge();
					items = front->getItems();
					delete rear;
					rear = nullptr;
					front = nullptr;
				}
				else
				{
					age = front->getAge();
					items = front->getItems();
					Node* temp = front;
					front = front->getNext();
					delete temp; 
					temp = nullptr;
				}
				--qSize;
	}

	bool isEmpty()
	{
		if (front == nullptr)
			return true;
		else
			return false;
	}
};

int lowestItems(Queue*& Q)
{
	int min = 0;
	int minItems =10000;
	int j;
	int age, items;
	int comp;
	for (int i = 0; i < 4; ++i)
	{
		j = 0;
		comp = 0;
		while (j < Q[i].qSize)
		{
			Q[i].Dequeue(age, items);
			comp = comp + items;
			Q[i].Enqueue(age, items);
			++j;
		}
		if (comp < minItems)
		{
			minItems = comp;
			min = i;
		}
	}
	return min;
}

void CheckAge(Queue*&q,int age,int items,bool flagP)
{
	bool flag = true;
	int A, I;
	/*for (int i = 0; i < 4; ++i)
	{
		if (q[i].front->getAge() < age)
		{
			flag = true;
			break;
		}
		else 
		{
			flag = false;
		}
	}*/

	if (flagP)
	{
		int index = lowestItems(q);
		int j = 0;
		q[index].Enqueue(age, items);
		while (j < q[index].qSize-1)
		{
			q[index].Dequeue(A, I);
			q[index].Enqueue(A, I);
			++j;
		}
	}
	else
	{
		int index = lowestItems(q);
		q[index].Enqueue(age, items);
	}
}

void CorrectEnqueue(int age,int items, Queue*& Q,bool flagP)
{
	bool flag = true;
	int first;
	for (int i = 0; i < 4; ++i)
	{
		if (Q[i].isEmpty())
		{
			first = i;
			flag = false;
			break;
		}
	}
	if (!flag)
	{
		Q[first].Enqueue(age, items);
	}
	else if (flag)
	{
		CheckAge(Q, age, items,flagP);
	}
}

void DisplayCounters(Queue*&Q)
{
	int j = 0;
	int age, items;
	for (int i = 0; i < 4; ++i)
	{
		j = 0;
		cout << " Queue (Age,Items) " << i + 1 << endl;
		if (Q[i].isEmpty())
		{
			cout << "The Queue is Empty" << endl;
		}
		else
		{
			while (j < Q[i].qSize)
			{
				Q[i].Dequeue(age, items);
				Q[i].Enqueue(age, items);
				cout << "(" << age << "," << items << ")" << "  ,  ";
				++j;
			}
		}
		cout << endl;
		cout << "------------------------------------" << endl;
	}
}

int main()
{
	int counter = 4;
	int maxAge = 0;
	Queue* counters = new Queue[counter];
	bool flag = true;
	int age, items;
	char input;
	while (flag)
	{
		cout << "Enter The Age : " << endl;
		cin >> age;
		if (age > maxAge)
		{
			maxAge = age;
			flag = true;
		}
		else
		{
			flag = false;
		}
		cout << "Enter Items : " << endl;
		cin >> items;
		CorrectEnqueue(age, items,counters,flag);
		cout << "The respective counters are :" << endl;
		DisplayCounters(counters);
		cout << "Do you want to pay your bills(Y / N) : Y" << endl;
		cin >> input;
		while (input != 'Y' && input != 'N')
		{
			cout << "Enter correct input" << endl;
			cin >> input;
		}
		if (input == 'Y')
			flag = true;
		else
			flag = false;
	}
}