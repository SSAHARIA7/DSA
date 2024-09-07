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


Node* findIntersection(Node *firstHead, Node *secondHead)
{
    Node *temp1 = firstHead;
    Node *temp2 = secondHead;

    while(temp1 != temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
        if(temp1 == temp2) return temp1;

        if(temp1==nullptr) temp1=secondHead;
        if(temp2 == nullptr) temp2 = firstHead; 
    }
    return temp1;
}