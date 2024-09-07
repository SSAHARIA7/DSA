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
bool isPalindrome(Node *head){
   Node *fast = head;
   Node *slow = head;

   while(fast->next != nullptr && fast->next->next != nullptr){
    fast = fast->next->next;
    slow = slow->next;
   }
    Node *newHead = reverseLinkedList(slow->next);
    Node *first = head;
    Node *second = newHead;
    bool ans{true};
    while(second != nullptr){
        if(first->data != second->data){
            ans = false;
            break;
        }
        first = first->next;
        second = second->next; 
    }
    reverseLinkedList(newHead);
    return ans;
}