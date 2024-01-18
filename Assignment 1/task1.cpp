//#include<iostream>
//using namespace std;
//template <typename T>
//class SortedSet {
//private:
//    struct Node {
//        T data;
//        Node* next;
//
//        Node(const T& value) {
//            data = value;
//            next = nullptr;
//        }
//        void setData(T d)
//        {
//            data = d;
//        }
//        void setNext(Node* ptr)
//        {
//            next = ptr;
//        }
//        Node* getNext()
//        {
//            return next;
//        }
//        T getData()
//        {
//            return data;
//        }
//    };
//    Node* head;
//    Node* tail;
//    int size;
//public:
//    SortedSet()
//    {
//        head = nullptr;
//        tail = nullptr;
//        size = 0;
//    }
//    int getSize()
//    {
//        return size;
//    }
//    bool checkData(T data)
//    {
//        bool flag = true;
//        if (head != nullptr)
//        {
//            Node* temp = head;
//            while (temp != nullptr)
//            {
//                if (data == temp->getData())
//                {
//                    flag = false;
//                    return flag;
//                    break;
//                }
//                temp = temp->getNext();
//            }
//            return flag;
//        }
//    }
//    void insert(T data)
//    {
//        if (head == nullptr)
//        {
//            Node* newNode = new Node(data);
//            head = newNode;
//            tail = newNode;
//            newNode->setNext(nullptr);
//            tail->setNext(nullptr);
//            ++size;
//        }
//        else{
//            Node* temp = head;
//            Node* prev = head;
//            
//                if (checkData(data))
//                {
//                    while (temp != nullptr)
//                    {
//                        if (data < head->getData())
//                        {
//                            Node* newNode = new Node(data);
//                            newNode->setNext(head);
//                            head = newNode;
//                            ++size;
//                            break;
//                        }
//                        else if (data > prev->getData() && data < temp->getData())
//                        {
//                            Node* newNode = new Node(data);
//                            newNode->setNext(temp);
//                            prev->setNext(newNode);
//                            ++size;
//                            break;
//                        }
//                        else if (data > tail->getData())
//                        {
//                            Node* newNode = new Node(data);
//                            tail->setNext(newNode);
//                            newNode->setNext(nullptr);
//                            tail = newNode;
//                            ++size;
//                            break;
//                        }
//                        prev = temp;
//                        temp = temp->getNext();
//                    }
//                }
//                else
//                {
//                    cout << "Duplicate Data exists\n";
//                }
//        }
//    }
//    void deleteData(int index)
//    {
//        if (head != nullptr)
//        {
//            Node* temp = head;
//            Node* prev = head;
//            int i = 0;
//            while (temp != nullptr)
//            {
//                if (i == index)
//                {
//                    prev->setNext(temp->getNext());
//                    delete temp;
//                    temp = nullptr;
//                    --size;
//                    break;
//                }
//                prev = temp;
//                temp = temp->getNext();
//                ++i;
//            }
//        }
//    }
//    void print()const
//    {
//        Node* current = head;
//        while (current != nullptr)
//        {
//            cout << current->getData() << " -> ";
//            current = current->getNext();
//        }
//    }
//    void Union(SortedSet<T>const&otherSet)
//    {
//        Node* current = otherSet.head;
//        while (current != nullptr)
//        {
//            if (this->checkData(current->getData()))
//            {
//                this->insert(current->getData());
//            }
//            current=current->getNext();
//        }
//    }
//};
//int main()
//{
//    SortedSet<int>List1;
//    int data;
//    for (int i = 0; i < 10; ++i)
//    {
//        cout << "Enter data" << endl;
//        cin >> data;
//        List1.insert(data);
//    }
//    List1.print();
//    cout << endl;
//    int index;
//    cout << "Enter the index from where you want to delete the data " << endl;
//    cin >> index;
//    while (index<0 || index>List1.getSize())
//    {
//        cout << "Enter correct index" << endl;
//        cin >> index;
//    }
//    List1.deleteData(index);
//    cout << "The list after deleting from " << index << " index is " << endl;
//    List1.print(); cout << endl;
//
//    SortedSet<int>List2;
//    cout << "Now enter data for the second list" << endl;
//    for (int i = 0; i < 10; ++i)
//    {
//        cout << "Enter data" << endl;
//        cin >> data;
//        List2.insert(data);
//    }
//    cout << endl;
//    List2.print();
//    cout << "\n";
//    List1.Union(List2);
//    cout << "The Union of the two Lists is :" << endl;
//    List1.print();
//    cout << "\n";
//}