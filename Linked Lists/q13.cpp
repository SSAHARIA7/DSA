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
    
}

Node* deleteMiddle(Node* head){
    Node *fast = head;
    Node *slow = head;

    while(fast != nullptr && fast->next != nullptr){
        if(fast != head){  // To stop at 1 element before middle
            slow = slow->next;
        }
        fast = fast->next->next;
    }

        if(head->next == nullptr) return nullptr;
        if(head->next->next == nullptr){
            Node *temp = head->next;
            head->next = nullptr;
            delete temp;
            return head; 
        }
    
    Node *temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    

    return head;
}