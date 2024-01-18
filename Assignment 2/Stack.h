#ifndef STACK_H
#define STACK_H

#include <cstddef>

template <class T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& val) : data(val), next(nullptr) {}
    };

    Node* topNode;

public:
    Stack() : topNode(nullptr) {}

    ~Stack() {
        while (!IsEmpty()) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    bool IsEmpty() const {
        if (topNode == nullptr)
            return true;
        else
            return false;
    }

    void Push(const T& val) {
        Node* newNode = new Node(val);
        newNode->next = topNode;
        topNode = newNode;
    }

    bool Pop(T& val) {
        if (IsEmpty()) {
            return false; // Stack is empty
        }
        Node* temp = topNode;
        val = temp->data;
        topNode = topNode->next;
        delete temp;
        return true;
    }

    bool Top(T&val) const {
        ;
        if (IsEmpty()) {
            return false; // Stack is empty
        }
        val = topNode->data;
        return true;
    }
};

#endif  // STACK_H
