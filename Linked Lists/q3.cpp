#include <iostream>

class Node
{
public:
    int data;
    Node* next;
    Node(int data)
    { 
        this->data = data;
        next = NULL;
    }
};


Node* oddEvenList(Node* head)
{
    Node *evenHead = nullptr;
    if(head->next){
        Node *evenHead = head->next;
    }else{
        return head;
    }
    Node *oddMover = head;
    Node *evenMover = evenHead;

    while(oddMover->next->next != nullptr){
        oddMover->next = oddMover->next->next;
        oddMover = oddMover->next->next;
        if(evenMover->next->next != nullptr){
            evenMover->next = evenMover->next->next; 
            evenMover = evenMover->next->next;
        }
    }
    oddMover->next = evenHead;
    return head;
}