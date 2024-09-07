#include <iostream>
class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };


Node * merge(Node *head1, Node *head2){
    
    Node *temp = head1->data > head2->data ? head2 : head1;
    Node *temp1 = head1->data > head2->data ? head1 : head2;
    Node *temp2 = temp->next;
    Node *ansHead = temp;

    while(temp1 != nullptr && temp2 != nullptr){
        if(temp1->data > temp2->data){
            temp->next = temp2;
            temp2 = temp2->next;
        }else{
            temp->next = temp1;
            temp1 = temp1->next;
        }

        temp = temp->next;

    }

    if(temp1 == nullptr){
        temp->next = temp2;
    }else if(temp2 == nullptr){
        temp->next = temp1;
    }
    return ansHead;
}




Node *mergeSort(Node *head){
    if(head == nullptr || head->next == nullptr) return head;
    
    Node *fast = head;
    Node *slow = head;
    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    slow->next = nullptr;
    Node *head1 = nullptr;
    Node *head2 = nullptr;
    Node *head1 = mergeSort(head);
    Node *head2 = mergeSort(fast);
    Node *sortedHead = merge(head1,head2);
    return sortedHead;

}
    
Node *sortLL(Node *head)
{
    head = mergeSort(head);
    return head;
}
