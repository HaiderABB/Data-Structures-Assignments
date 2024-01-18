//#include<iostream>
//using namespace std;
//template<typename t>
//class stack {
//private:
//	class node {
//		t data;
//		node* next;
//		node* prev;
//	public:
//		node(t data)
//		{
//			this->data = data;
//			next = nullptr;
//			prev = nullptr;
//		}
//		t getdata()
//		{
//			return data;
//		}
//		void setnext(node* next)
//		{
//			this->next = next;
//		}
//		node* getnext()
//		{
//			return next;
//		}
//		node* getprev()
//		{
//			return prev;
//		}
//		void setprev(node* prev)
//		{
//			this->prev = prev;
//		}
//	};
//public:
//	node* head;
//	node* tail;
//	node* current;
//	bool flipped;
//	stack()
//	{
//		head = nullptr;
//		current = nullptr;
//		tail = nullptr;
//		flipped = false;
//	}
//	bool isempty()
//	{
//		if (tail == nullptr)
//		{
//			return true;
//		}
//		else
//			return false;
//	}
//	void push(t data)
//	{
//		if (isempty())
//		{
//			node* newnode = new node(data);
//			head = newnode;
//			head->setprev(nullptr);
//			tail = newnode;
//			newnode->setnext(nullptr);
//			current = newnode;
//		}
//		else
//		{
//			node* newnode = new node(data);
//			current->setnext(newnode);
//			newnode->setprev(current);
//			newnode->setnext(nullptr);
//			current = newnode;
//			tail = newnode;
//		}
//	}
//	t pop()
//	{
//		t val;
//		if (!flipped && tail != head)
//		{
//			val = tail->getdata();
//			node* temp = tail;
//			tail = tail->getprev();
//			delete temp;
//			return val;
//		}
//		else if (flipped && tail != head)
//		{
//			val = tail->getdata();
//			node* temp = tail;
//			tail = tail->getnext();
//			delete temp;
//			return val;
//		}
//		else if (tail == head)
//		{
//			val = head->getdata();
//			delete head;
//			head = nullptr;
//			tail = nullptr;
//			current = nullptr;
//			return val;
//		}
//	}
//	t getTop()
//	{
//		return tail->getdata();
//	}
//	void flipstack()
//	{
//		flipped = !flipped;
//		node* temp = tail;
//		tail = head;
//		head = temp;
//	}
//	~stack() {
//		while (!isempty())
//		{
//			pop();
//		}
//		head = nullptr;
//		current = nullptr;
//		tail = nullptr;
//	}
//};
//
//int main()
//{
//	stack<int>Stack;
//	for (int i = 1; i < 6; ++i)
//	{
//		Stack.push(i);
//	}
//	cout << "top is " << Stack.getTop() << endl;
//	cout << "popped is " << Stack.pop() << endl;
//	cout << "top is " << Stack.getTop() << endl;
//
//	Stack.flipstack();
//	cout << "top is " << Stack.getTop() << endl;
//	cout << "popped is " << Stack.pop() << endl;
//	cout << "top is " << Stack.getTop() << endl;
//	cout << "popped is " << Stack.pop() << endl;
//	cout << "top is " << Stack.getTop() << endl;
//	Stack.flipstack();
//	cout << "top is " << Stack.getTop() << endl;
//	cout << "popped is " << Stack.pop() << endl;
//	cout << "top is " << Stack.getTop() << endl;
//	cout << "popped is " << Stack.pop() << endl;
//}