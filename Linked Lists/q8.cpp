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

Node *addOne(Node *head)
{
    Node *newHead = reverseLinkedList(head);

    int carry = 1;

    Node *temp = newHead;

    while(temp != nullptr && carry != 0){
        if(temp->data != 9) {
            temp->data++;
            carry = 0;
        }else{
            temp->data = 0;
            carry = 1;
        }
        temp = temp->next;
    }
    reverseLinkedList(newHead);
    if(carry == 1){
        Node *ans = new Node (1);
        ans->next = head;
        return ans;
    }

    return head;
}


//RECURSIVE also possible.