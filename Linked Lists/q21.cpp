#include <iostream>

 class Node {
   public:
 		int data;
 		Node *next;
  		Node *child;
 		Node() : data(0), next(nullptr), child(nullptr){};
 		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
  };


Node* flattenLinkedList(Node* head) 
{

    Node *newHead = head->data>head->next->data?head->next:head; 
    Node *headNext = head->next;
    head->next = nullptr;
    while(headNext != nullptr){
        Node *temp1 = head->data>headNext->data?headNext:head; 
        Node *temp2 = head->data>headNext->data?head:headNext; 
        Node *temp = temp1->child;
        Node *delNextPtr = headNext;
        if(newHead->data >= temp1->data) newHead = temp1;
        headNext = headNext->next;
        delNextPtr->next = nullptr;
        head = temp1;
        while(temp != nullptr && temp2 != nullptr){
            if(temp->data > temp2->data){
                temp1->child = temp2;
                temp2 = temp2->child;
            }else{
                temp1->child = temp;
                temp = temp->child;
            }
            temp1 = temp1->child;
        }
        if(temp == nullptr){
            temp1->child = temp2;
        }else{
            temp1->child = temp;
        }
    }


   
    return newHead;

}