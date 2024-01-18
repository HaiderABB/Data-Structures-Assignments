#include<iostream>
using namespace std;
class Queue {
private:
	int front, rear;
	int* data;
	int cap;
	int size = 0;
public:
	Queue(int cap)
	{
		front = rear = -1;
		data = new int[cap];
		this->cap = cap;
	}
	void Enqueue(int i)
	{
		if (front == -1)
		{
			rear = getNext(rear);
			front = getNext(front);
			data[rear] = i;
		}
		else
		{
			rear = getNext(rear);
			data[rear] = i;
		}
		++size;
	}
	int Dequeue()
	{
		int d = data[front];
		if (front == rear)
			front = rear = -1;
		else
			front = getNext(front);

		--size;
		return d;
	}
	int getNext(int i)
	{
		return (i + 1) % cap;
	}
	bool isEmpty()
	{
		if (front == -1)
			return true;
		else
			return false;
	}
	int getSize()
	{
		return size;
	}
};

int Joseph(int n, int k)
{
	Queue circle(n);
	
	for (int i = 1; i <= n; ++i)
	{
		circle.Enqueue(i);
	}

	int data; 

	while (!circle.isEmpty())
	{
			for (int i = 1; i < k; ++i)
			{
				data = circle.Dequeue();
				circle.Enqueue(data);
			}
			int executed = circle.Dequeue();
			if (circle.isEmpty()) {
				return executed;
			}
	}
}
int main()
{
	int n, k;
	cout << "Enter n" << endl;
	cin >> n;
	cout << "Enter k" <<endl;
	cin >> k;
	int Survivor = Joseph(n, k);
	cout << "Survivor is " << Survivor <<endl;
}