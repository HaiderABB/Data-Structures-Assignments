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
//        else {
//            Node* temp = head;
//            Node* prev = head;
//
//            if (checkData(data))
//            {
//                while (temp != nullptr)
//                {
//                    if (data < head->getData())
//                    {
//                        Node* newNode = new Node(data);
//                        newNode->setNext(head);
//                        head = newNode;
//                        ++size;
//                        break;
//                    }
//                    else if (data > prev->getData() && data < temp->getData())
//                    {
//                        Node* newNode = new Node(data);
//                        newNode->setNext(temp);
//                        prev->setNext(newNode);
//                        ++size;
//                        break;
//                    }
//                    else if (data > tail->getData())
//                    {
//                        Node* newNode = new Node(data);
//                        tail->setNext(newNode);
//                        newNode->setNext(nullptr);
//                        tail = newNode;
//                        ++size;
//                        break;
//                    }
//                    prev = temp;
//                    temp = temp->getNext();
//                }
//            }
//            else
//            {
//                cout << "Duplicate Data exists\n";
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
//    void rotate(int index)
//    {
//        if (index > 0)
//        {
//            Node* current = tail;
//            int i = 0;
//            Node* temp = head;
//            while (index != i)
//            {
//                current->setNext(temp);
//                current = current->getNext();
//                temp = temp->getNext();
//                ++i;
//            }
//            head = temp;
//            tail = current;
//            tail->setNext(nullptr);
//        }
//    }
//};
//int main()
//{
//    SortedSet<int>List;
//    int index;
//    for (int i = 1; i <= 10; ++i)
//    {
//        List.insert(i);
//    }
//    cout << "\n-------------------------------\n";
//    cout << "The Nodes of the list are " << endl;
//    List.print();
//    cout << "\n-------------------------------\n";
//    cout << "Enter the index from which you want to rotate the List" << endl;
//    cin >> index;
//    while (index < 0 || index >= List.getSize())
//    {
//        cout << "Enter a valid index" << endl;
//        cin >> index;
//    }
//    List.rotate(index);
//    cout << "\n-------------------------------\n";
//    cout << "After rotating the list from " << index << " index, the list becomes " << endl;
//    List.print();
//}