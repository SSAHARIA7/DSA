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

//ITERATIVE
Node* reverseLinkedList(Node *head){
    if(head == nullptr || head->next == nullptr) return head;
    Node *next = head->next;
    head->next = nullptr;
    Node *prev = head;
    head = next ;
    next = next->next;

    while(next != nullptr){
        head->next = prev;
        prev = head;
        head = next;
        next = next->next;
    }

    head->next = prev;
    return head;

}

//RECURSIVE

Node* reverseLinkedList(Node *head)
{
    if(head == nullptr || head->next == nullptr) return head;

    Node *newHead = reverseLinkedList(head->next);

    Node *front = head->next;
    front->next = head;
    head->next = nullptr;

    return newHead;
}
