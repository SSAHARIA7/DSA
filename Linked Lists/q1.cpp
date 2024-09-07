#include <iostream>

class Node
{
public:
    int data;
    Node *next,*prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev= NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};


Node* reverseDLL(Node* head)
{   
    while(head->next != nullptr){
        Node *temp = head->next;
        head->next = head->prev;
        head->prev = temp;
        head = temp;
    }
    head->next = head->prev;
    head->prev = nullptr;
    return head;
}



int main(){


    return 0;
}