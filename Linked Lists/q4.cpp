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


Node* sortList(Node *head){
    Node *zeroHead = nullptr;
    Node *zeroMover = nullptr;
    Node *oneHead = nullptr, *oneMover = nullptr;
    Node *twoHead = nullptr, *twoMover = nullptr;

    Node *current = head;
    Node *next = nullptr;
    while(current != nullptr){
        next = current->next;
        if(current->data == 0){
            if(zeroHead == nullptr){
                zeroHead = current;
                zeroMover =current;
            }else{
                zeroMover -> next = current;
                zeroMover = zeroMover->next;
            }
        }else if(current->data == 1){
            if (oneHead == nullptr){
                oneHead = current;
                oneMover =  current;
            }else{
                oneMover -> next = current;
                oneMover =oneMover->next;
            }
        }else{
             if (twoHead == nullptr){
                twoHead = current;
                twoMover =  current;
            }else{
                twoMover -> next = current;
                twoMover =twoMover->next;
            }
        }
        current = next;
    }
    zeroMover->next = oneHead;
    oneMover ->next = twoHead;
    twoMover -> next = nullptr;
    return zeroHead;
}