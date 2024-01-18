#pragma once
#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
using namespace std;

//                          Linked List Classes
class Node {
private:
	int ID;
	string URL;
	string Keyword;
	Node* next;
public:
	Node()
	{
		next = nullptr;
	}
	Node(int ID, string URL, string Keyword)
	{
		this->ID = ID;
		this->URL = URL;
		this->Keyword = Keyword;
		next = nullptr;
	}
	void setNext(Node* temp)
	{
		next = temp;
	}
	Node* getNext()
	{
		return next;
	}
	void setData(int ID, string URL, string Keyword)
	{
		this->ID = ID;
		this->URL = URL;
		this->Keyword = Keyword;
	}
	string getKeyword()
	{
		return Keyword;
	}
	string getURL()
	{
		return URL;
	}
	int getID()
	{
		return ID;
	}
};
class List {
	Node* head;
	Node* tail;
	Node* current;
	int size = 0;
public:
	List()
	{
		head = nullptr;
		tail = nullptr;
		current = nullptr;
	}
	void AddNode(int ID, string URL, string Keyword)
	{
		Node* newNode = new Node(ID, URL, Keyword);
		if (head == nullptr)
		{
			head = newNode;
			current = newNode;
			tail = newNode;
			newNode->setNext(nullptr);
		}
		else
		{
			current->setNext(newNode);
			tail = newNode;
			tail->setNext(nullptr);
			current = newNode;
		}
		++size;
	}
	void searchList(string word, List& obj)
	{
		string desc;
		Node* ptr = head;
		bool check = false;
		while (ptr != nullptr)
		{
			desc = ptr->getKeyword();
			size_t found = desc.find(word);
			if (found != std::string::npos)
			{
				obj.AddNode(ptr->getID(), ptr->getURL(), ptr->getKeyword());
				check = true;
			}
			ptr = ptr->getNext();
		}
		if (check == false)
			cout << "Word not found in any of the URL" << endl;

	}
	void viewData()
	{
		cout << size << " result(s) found" << endl;
		Node* ptr = head;
		while (ptr != nullptr)
		{
			cout << ptr->getURL() << endl;
			ptr = ptr->getNext();
		}
	}
};


//                          Tree Classes
class BSTnodes {
	string Keyword;
	List URLs;
	BSTnodes* left;
	BSTnodes* right;

public:
	BSTnodes()
	{
		left = nullptr;
		right = nullptr;
	}
	BSTnodes(string Keyword,List URLs)
	{
	
		this->Keyword = Keyword;
		this->URLs = URLs;
	
	}
	void setKeyword(string Keyword)
	{

		this->Keyword = Keyword;

	}
	BSTnodes* getRight()
	{
		return right;
	}
	BSTnodes* getLeft()
	{
		return left;
	}
	string getKeyword(){
		return Keyword;
	}
	List getURLs()
	{
		return URLs;
	}
	
	void setRight(BSTnodes* right)
	{
		this->right = right;
	}
	void setLeft(BSTnodes* left)
	{
		this->left = left;
	}
};
class BST {
	BSTnodes* root;
public:
	BST()
	{
		root = nullptr;
	}
	BSTnodes* getRoot()
	{
		return root;
	}
	void inTrav(BSTnodes* s)
	{
		if (s == nullptr)
			return;
		else
		{
			inTrav(s->getLeft());
			cout << s->getKeyword() << " ";
			inTrav(s->getRight());
		}
	}
	bool insert(string Keyword, List URLs)
	{
		if (root == nullptr)
		{
			root = new BSTnodes(Keyword,URLs);
			return true;
		}
		else
		{
			bool flag = true;
			bool check = false;
			BSTnodes* temp = root;
			while (flag)
			{
				if (Keyword > temp->getKeyword())
				{
					if (temp->getRight() == nullptr)
					{
						temp->setRight( new BSTnodes(Keyword,URLs));
						temp = temp->getRight();
						check = true;
						flag = false;
					}
					else
					{
						temp = temp->getRight();
					}
				}
				else if (Keyword < temp->getKeyword())
				{
					if (temp->getLeft() == nullptr)
					{
						temp->setLeft(new BSTnodes(Keyword,URLs));
						temp = temp->getLeft();
						flag = false;
						check = true;
					}
					else
					{
						temp = temp->getLeft();
					}
				}
				else if (Keyword == temp->getKeyword())
				{
					flag = false;
				}
			}

			if (check)
			{
				return true;
			}
			else
				return false;
		}
	}
	BSTnodes* findInOrder(BSTnodes* s)
	{
		BSTnodes* curr = s;
		while (curr && curr->getLeft() != nullptr)
		{
			curr = s->getLeft();
		}
		return curr;
	}
	BSTnodes* deleteInBST(BSTnodes* s, string Keyword) {
		if (s == nullptr) {
			return nullptr;
		}

		if (Keyword < s->getKeyword()) {
			s->setLeft(deleteInBST(s->getLeft(), Keyword));
		}
		else if (Keyword > s->getKeyword()) {
			s->setRight(deleteInBST(s->getRight(), Keyword));
		}
		else {
			if (s->getRight() == nullptr) {
				BSTnodes* temp = s->getLeft();
				delete s;
				return temp;
			}
			else if (s->getLeft() == nullptr) {
				BSTnodes* temp = s->getRight();
				delete s;
				return temp;
			}
			BSTnodes* temp = findInOrder(s->getRight());
			s->setKeyword(temp->getKeyword());
			cout << endl; this->inTrav(root); cout << endl;
			s->setRight(deleteInBST(s->getRight(), temp->getKeyword()));
		}

		return s;
	}
	int height(BSTnodes* s)
	{
		if (s == nullptr)
			return -1;
		int lh = height(s->getLeft());
		int rh = height(s->getRight());

		if (lh > rh)
			return lh + 1;
		else
			return rh + 1;
		return lh + 1;
	}
	void destructor(BSTnodes* s)
	{
		if (s == nullptr)
			return;

		destructor(s->getLeft());
		destructor(s->getRight());
		delete s;
		s = nullptr;
	}
	bool Search(string key,BSTnodes*s)
	{
		if (s == nullptr)
			return false;
		if (key == s->getKeyword())
			return true;

		if (key < s->getKeyword())
		{
			s = s->getLeft();
			return Search(key, s);
		}
		else if (key > s->getKeyword())
		{
			s = s->getRight();
			return Search(key, s);
		}
	}
	~BST()
	{
		/*destructor(root);*/
	}

};



