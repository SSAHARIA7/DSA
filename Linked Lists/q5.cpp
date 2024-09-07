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



Node* removeKthNode(Node* head, int K)
{
    Node *fast = head;
    Node *slow = head;
    for(int i{}; i<K ;i++){
        fast = fast->next;
    }
    if(fast == nullptr){
        return head->next;
    }
    while(fast->next != nullptr){
        fast = fast->next;
        slow = slow->next;
    }

    Node *delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;
    return head;



}
