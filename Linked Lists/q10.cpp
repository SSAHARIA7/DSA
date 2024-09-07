#include <iostream>

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};


Node *findMiddle(Node *head) {
    Node *fast = head;
    Node *slow = head;

    while(fast->next != nullptr && fast->next->next !=nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    if(fast->next == nullptr) return slow;
    if(fast->next->next == nullptr) return slow->next;
}