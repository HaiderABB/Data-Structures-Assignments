//#include<iostream>
//using namespace std;
//template<typename t>
//class Stack {
//private:
//	class Node {
//		t data;
//		Node* next;
//		Node* prev;
//	public:
//		Node(t data)
//		{
//			this->data = data;
//			next = nullptr;
//			prev = nullptr;
//		}
//		t getdata()
//		{
//			return data;
//		}
//		void setnext(Node* next)
//		{
//			this->next = next;
//		}
//		Node* getnext()
//		{
//			return next;
//		}
//		Node* getprev()
//		{
//			return prev;
//		}
//		void setprev(Node* prev)
//		{
//			this->prev = prev;
//		}
//	};
//public:
//	Node* head;
//	Node* tail;
//	Node* current;
//	bool flipped;
//	Stack()
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
//			Node* newnode = new Node(data);
//			head = newnode;
//			head->setprev(nullptr);
//			tail = newnode;
//			newnode->setnext(nullptr);
//			current = newnode;
//		}
//		else
//		{
//			Node* newnode = new Node(data);
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
//			Node* temp = tail;
//			tail = tail->getprev();
//			delete temp;
//			return val;
//		}
//		else if (flipped && tail != head)
//		{
//			val = tail->getdata();
//			Node* temp = tail;
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
//	t gettop()
//	{
//		return tail->getdata();
//	}
//	void deleteHead()
//	{
//		Node* temp = head;
//		head = head->getnext();
//		delete temp;
//		temp = nullptr;
//	}
//	~Stack() {
//		while (!isempty())
//		{
//			pop();
//		}
//		head = nullptr;
//		current = nullptr;
//		tail = nullptr;
//	}
//};
//class UndoStack
//{
//private:
//	Stack<int>stack;
//	int count;
//public:
//	UndoStack()
//	{
//		count = 0;
//	}
//	void push(int data)
//	{
//		if (count >= 100)
//		{
//			stack.deleteHead();
//			stack.push(data);
//			++count;
//		}
//		else
//		{
//			stack.push(data);
//			++count;
//		}
//	}
//	int pop()
//	{
//		return stack.pop();
//	}
//	~UndoStack()
//	{
//
//	}
//};
//int main()
//{
//	UndoStack UDstack;
//	for (int i = 1; i <= 100; ++i)
//	{
//		UDstack.push(i);
//	}
//	UDstack.push(678);
//	cout<<UDstack.pop();
//}