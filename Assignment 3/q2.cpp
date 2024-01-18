//#include<iostream>
//using namespace std;
//
//class Queue {
//private:
//	class Node {
//		Node* next;
//		int data;
//	public:
//		Node(int d)
//		{
//			next = nullptr;
//			data = d;
//		}
//		int getData()
//		{
//			return data;
//		}
//		void setNext(Node* next)
//		{
//			this->next = next;
//		}
//		Node* getNext()
//		{
//			return next;
//		}
//		~Node()
//		{
//			
//		}
//	};
//	Node*front;
//	Node*rear;
//public:
//	Queue()
//	{
//		front = nullptr;
//		rear = nullptr;
//	}
//	void Enqueue(int i)
//	{
//		if (front == nullptr)
//		{
//			Node* newNode = new Node(i);
//			front = newNode;
//			rear = newNode;
//			newNode->setNext(nullptr);
//		}
//		else
//		{
//			Node* newNode = new Node(i);
//			rear->setNext(newNode);
//			rear = newNode;
//			newNode->setNext(nullptr);
//		}
//	}
//	int Dequeue()
//	{
//		int data;
//		if (front == rear)
//		{
//			data = front->getData();
//			delete rear;
//			rear = nullptr;
//			front = nullptr;
//		}
//		else
//		{
//			data = front->getData();
//			Node* temp = front;
//			front = front->getNext();
//			delete temp; 
//			temp = nullptr;
//		}
//		return data;
//	}
//	bool isEmpty()
//	{
//		if (front == nullptr)
//			return true;
//		else
//			return false;
//	}
//};
//
//void radixSort(int m,int k, Queue&q)
//{
//	Queue*arrayQ = new Queue[m];
//	int n, digit;
//	for (int i = 0; i < k; ++i)
//	{
//		while (!q.isEmpty())
//		{
//			n = q.Dequeue();
//			if (i == 0)
//			{
//				digit = n % 10;
//			}
//			else if (i == 1)
//			{
//				int p;
//				p = n / 10;
//				digit = (p) % 10;
//			}
//			else {
//				digit = n / 100;
//			}
//			arrayQ[digit].Enqueue(n);
//		}
//		for (int j = 0; j < m; ++j)
//		{
//			    while(!arrayQ[j].isEmpty())
//				{
//					q.Enqueue(arrayQ[j].Dequeue());
//				}
//		}
//	}
//
//	cout << "After running Radix Sort" << endl;
//	while (!q.isEmpty())
//	{
//		cout << q.Dequeue() << endl;
//	}
//
//}
//
//int main()
//{
//	int m, k;
//	cout << "Enter m " << endl;
//	cin >> m;
//	cout << "Enter k" << endl;
//	cin >> k;
//	Queue mainQ;
//	mainQ.Enqueue(123);
//	mainQ.Enqueue(567);
//	mainQ.Enqueue(324);
//	mainQ.Enqueue(321);
//	mainQ.Enqueue(909);
//	mainQ.Enqueue(342);
//	mainQ.Enqueue(125);
//	mainQ.Enqueue(516);
//	mainQ.Enqueue(678);
//	mainQ.Enqueue(340);
//
//	radixSort(m, k,mainQ);
//}