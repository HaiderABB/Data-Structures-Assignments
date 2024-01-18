#include<iostream>
using namespace std;
template <typename T>
class SortedSet {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) {
            data = value;
            next = nullptr;
        }
        void setData(T d)
        {
            data = d;
        }
        void setNext(Node* ptr)
        {
            next = ptr;
        }
        Node* getNext()
        {
           return next;
        }
        T getData()
        {
            return data;
        }
    };
    Node* head;
    Node* tail;
    int size;
public:
    SortedSet()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    int getSize()
    {
        return size;
    }
    bool checkData(T data)
    {
        bool flag = true;
        if (head != nullptr)
        {
            Node* temp = head;
            while (temp != nullptr)
            {
                if (data == temp->getData())
                {
                    flag = false;
                    return flag;
                    break;
                }
                temp = temp->getNext();
            }
            return flag;
        }
    }
    void insert(T data)
    {
        if (head == nullptr)
        {
            Node* newNode = new Node(data);
            head = newNode;
            tail = newNode;
            newNode->setNext(nullptr);
            tail->setNext(nullptr);
            ++size;
        }
        else {
            Node* temp = head;
            Node* prev = head;

            if (checkData(data))
            {
                while (temp != nullptr)
                {
                    if (data < head->getData())
                    {
                        Node* newNode = new Node(data);
                        newNode->setNext(head);
                        head = newNode;
                        ++size;
                        break;
                    }
                    else if (data > prev->getData() && data < temp->getData())
                    {
                        Node* newNode = new Node(data);
                        newNode->setNext(temp);
                        prev->setNext(newNode);
                        ++size;
                        break;
                    }
                    else if (data > tail->getData())
                    {
                        Node* newNode = new Node(data);
                        tail->setNext(newNode);
                        newNode->setNext(nullptr);
                        tail = newNode;
                        ++size;
                        break;
                    }
                    prev = temp;
                    temp = temp->getNext();
                }
            }
            else
            {
                cout << "Duplicate Data exists\n";
            }
        }
    }
    void print()const
    {
        Node* current = head;
        while (current != nullptr)
        {
            cout << current->getData() << " -> ";
            current = current->getNext();
        }
    }
    void reverseList()
    {
        Node* current = head->getNext();
        Node* prev = head;
        Node* temp;
        while (current != nullptr)
        {
            temp = current->getNext();
            current->setNext(prev);
            prev = current;
            current = temp;
        }
        temp = head;
        head = tail;
        tail = temp;
        tail->setNext(nullptr);
    }
};
int main()
{
    SortedSet<int>List;
        int index;
        for (int i = 1; i <= 10; ++i)
        {
            List.insert(i);
        }
        cout << "\n-------------------------------\n";
        cout << "The Nodes of the list are " << endl;
        List.print();
        cout << "\n-------------------------------\n";
        cout << "The reversed list is " << endl;
        List.reverseList();
        List.print();
}