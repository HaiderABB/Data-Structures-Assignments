#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Linked List Classes
class Node {
private:
    int ID;
    string URL;
    string Keyword;
    Node* next;

public:
    Node() {
        next = nullptr;
    }

    Node(int ID, string URL, string Keyword) {
        this->ID = ID;
        this->URL = URL;
        this->Keyword = Keyword;
        next = nullptr;
    }

    void setNext(Node* temp) {
        next = temp;
    }

    Node* getNext() {
        return next;
    }

    void setData(int ID, string URL, string Keyword) {
        this->ID = ID;
        this->URL = URL;
        this->Keyword = Keyword;
    }

    string getKeyword() {
        return Keyword;
    }

    string getURL() {
        return URL;
    }

    int getID() {
        return ID;
    }
};

class List {
    Node* head;
    Node* tail;
    Node* current;
    int size = 0;

public:
    List() {
        head = nullptr;
        tail = nullptr;
        current = nullptr;
    }

    void AddNode(int ID, string URL, string Keyword) {
        Node* newNode = new Node(ID, URL, Keyword);
        if (head == nullptr) {
            head = newNode;
            current = newNode;
            tail = newNode;
            newNode->setNext(nullptr);
        }
        else {
            current->setNext(newNode);
            tail = newNode;
            tail->setNext(nullptr);
            current = newNode;
        }
        ++size;
    }

    void searchList(string word, List& obj) {
        string desc;
        Node* ptr = head;
        bool check = false;
        while (ptr != nullptr) {
            desc = ptr->getKeyword();
            size_t found = desc.find(word);
            if (found != std::string::npos) {
                obj.AddNode(ptr->getID(), ptr->getURL(), ptr->getKeyword());
                check = true;
            }
            ptr = ptr->getNext();
        }
        if (check == false)
            cout << "Word not found in any of the URL" << endl;
    }

    void viewData() {
        cout << size << " result(s) found" << endl;
        Node* ptr = head;
        while (ptr != nullptr) {
            cout << ptr->getURL() << endl;
            ptr = ptr->getNext();
        }
    }
};

// Tree Classes
class AVLnodes {
public:
    string Keyword;
    List URLs;
    AVLnodes* left;
    AVLnodes* right;
    int height;

    AVLnodes(string Keyword, List URLs) : Keyword(Keyword), left(nullptr), right(nullptr), height(1), URLs(URLs) {}
};

class AVLtree {
private:
    AVLnodes* root;

    int getHeight(AVLnodes* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    int getBalanceFactor(AVLnodes* node) {
        if (node == nullptr) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    AVLnodes* rightRotate(AVLnodes* bottom) {
        AVLnodes* upper = bottom->left;
        AVLnodes* Temp = upper->right;

        upper->right = bottom;
        bottom->left = Temp;

        bottom->height = 1 + max(getHeight(bottom->left), getHeight(bottom->right));
        upper->height = 1 + max(getHeight(upper->left), getHeight(upper->right));

        return upper;
    }

    AVLnodes* leftRotate(AVLnodes* upper) {
        AVLnodes* bottom = upper->right;
        AVLnodes* Temp = bottom->left;

        bottom->left = upper;
        upper->right = Temp;

        upper->height = 1 + max(getHeight(upper->left), getHeight(upper->right));
        bottom->height = 1 + max(getHeight(bottom->left), getHeight(bottom->right));

        return bottom;
    }

    AVLnodes* insert(AVLnodes* node, List URLs, string Keyword) {
        if (node == nullptr) {
            return new AVLnodes(Keyword, URLs);
        }

        if (Keyword < node->Keyword) {
            node->left = insert(node->left, URLs, Keyword);
        }
        else if (Keyword > node->Keyword) {
            node->right = insert(node->right, URLs, Keyword);
        }
        else {
            return node;
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalanceFactor(node);

        // Left Left Case
        if (balance > 1 && Keyword < node->left->Keyword) {
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && Keyword > node->right->Keyword) {
            return leftRotate(node);
        }

        // Left Right Case
        if (balance > 1 && Keyword > node->left->Keyword) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && Keyword < node->right->Keyword) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

public:
    AVLtree() {
        root = nullptr;
    }

    AVLnodes* getRoot() {
        return root;
    }

    void insert(List URLs, string Keyword) {
        root = insert(root, URLs, Keyword);
    }

    void printInOrderTraversal(AVLnodes* node) {
        if (node == nullptr) return;

        printInOrderTraversal(node->left);
        cout << node->Keyword << " ";
        printInOrderTraversal(node->right);
    }

    void printInOrder() {
        printInOrderTraversal(root);
        cout << endl;
    }

    void search(string key,bool&flag,AVLnodes*node)
    {
        if (node == nullptr)
        {
            flag = false;
            return;
        }
        if (node->Keyword == key)
        {
            flag = true;
            return;
        }
        if (key < node->Keyword)
        {
            search(key, flag, node->left);
        }
        if (key > node->Keyword)
        {
            search(key, flag, node->right);
        }
    }

    ~AVLtree() {
    }
};

List URLlists;
List Temp;

void extractWords(string sentence, AVLtree& AVLdata) {
    string word;
    List TempURLs;
    for (char ch : sentence) {
        if (isalpha(ch) || ch == '\'') {
            word += ch;
        }
        else {
            if (!word.empty()) {
                URLlists.searchList(word, TempURLs);
                AVLdata.insert(TempURLs, word);
                word.clear();
            }
        }
    }
}

void readFromFile(string fileName, AVLtree& AVLdata) {
    ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        cerr << "Error opening the file!" << endl;
        return;
    }
    else {
        cout << "File loaded Successfully" << endl;
    }

    int ID;
    string URL, Keyword;

    while (inputFile >> ID >> URL) {
        // Skip the newline character
        inputFile.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(inputFile, Keyword);
        URLlists.AddNode(ID, URL, Keyword);
        extractWords(Keyword, AVLdata);
    }
    inputFile.close();
}

void searchWord(string word) {
    URLlists.searchList(word, Temp);
    Temp.viewData();
}

bool checkExtension(const string& fileName) {
    size_t dotPosition = fileName.find_last_of('.');
    if (dotPosition != std::string::npos) {
        string extension = fileName.substr(dotPosition + 1);
        return (extension == "txt");
    }
    return false;
}

void insertInAVl(string word,AVLtree&AVLdata)
{
    List t;
    URLlists.searchList(word,t);
    AVLdata.insert(t,word);
}

bool searchInAVL(string word,AVLtree&AVLdata)
{
    bool flag = false;
    AVLdata.search(word, flag, AVLdata.getRoot());
    return flag;
}

int main() {
    string fileName;
    cout << "Enter filename" << endl;
    cin >> fileName;

    while (!checkExtension(fileName)) {
        cout << "Enter correct Filename" << endl;
        cin >> fileName;
    }

    AVLtree AVLdata;
    readFromFile(fileName, AVLdata);

    AVLdata.printInOrder();
    cout << endl;
    cout << "Enter a word to insert in AVL" << endl;
    cin >> fileName;
    insertInAVl(fileName,AVLdata);
    cout << endl;
    AVLdata.printInOrder();
    cout << "Enter a word to search in AVL" << endl;
    cin >> fileName;
    if (searchInAVL(fileName, AVLdata))
    {
        cout << "Word found" << endl;
    }
    else
        cout << "Word not found" << endl;
    return 0;
}
