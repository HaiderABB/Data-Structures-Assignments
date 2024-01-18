#pragma once
#include<iostream>
#include<fstream>
using namespace std;

//class for managing of character data types
class Function
{
public:
	static int StringLength(const char*);
	static void StringCopy(char*&, const char*);
};
template <class T>
class Node
{
public:

	// Data Members
	T data;
	Node<T>* next;

	//Constructor
	Node(T value)
	{
		data = value;
		next = NULL;

	}
	//Destructor
	~Node()
	{

	}

};
//template based stack class

template <class T>
class Stack
{
private:
	Node<T>* head;
public:
	//Default constructor
	Stack()
	{
		head = NULL;

	}

	//whether stack is empty or not

	bool isEmpty()
	{
		return head == NULL;

	}

	//Inserting data into stack

	bool push(T& val)
	{
		Node <T>* New = new Node<T>(val);
		Node <T>* curr = head;


		if (head == NULL)
		{
			head = New;

		}
		else
		{
			New->next = head;
			head = New;
		}
		return true;
	}

	//Removing data from stack

	bool pop(T& val)
	{
		if (!isEmpty())
		{

			val = head->data;
			Node <T>* curr = head;
			head = head->next;
			delete curr;
			return true;
		}
		else
			return false;
	}

	//Getting Top of stack

	bool Top(T& val)
	{
		if (head != NULL)
		{
			val = head->data;
			return true;
		}
		else
			return false;
	}

	//Compare val with top of stack

	bool compare_T(char* val)
	{
		T obj;
		bool x = Top(obj);
		if (x == true)
		{
			int count = 0;
			int size1 = Function::StringLength(val);
			int size2 = Function::StringLength(obj.XML_text);
			for (int i = 0; obj.XML_text[i] != '\0'; i++)
			{
				if (obj.XML_text[i] == val[i])
					count++;
			}
			if (count == size1)
				return true;
			else
				return false;
		}
		else
			return false;
	}

	//Destructor

	~Stack()
	{

	}
};


//XML class

class XMLDATA
{

public:

	//Data Members

	int Line_Number;
	char* XML_text;

	//Default constructor of XML class
	XMLDATA()
	{
		Line_Number = -1;
		XML_text = NULL;

	}

	//Some Helper functions

	void Set_line_Number(int inp)
	{
		Line_Number = inp;

	}
	void Set_text(const char* inp)
	{
		Function::StringCopy(XML_text, inp);

	}
	void Print()
	{
		if (XML_text != NULL)
			cout << " Line number is " << Line_Number << " and text is " << XML_text << endl;
	}

	//Destructor
	~XMLDATA()
	{

	}

};