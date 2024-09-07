#include <iostream>


  class Node {
  public:
       int data;
       Node *prev;
       Node *next;
       Node() {
           this->data = 0;
           this->prev = NULL;
           this->next = NULL;
       }
       Node(int data) {
           this->data = data;
           this->prev = NULL;
           this->next = NULL;
       }
       Node (int data, Node *next, Node *prev) {
           this->data = data;
           this->prev = prev;
           this->next = next;
       }
  };
 

 
Node * deleteAllOccurrences(Node* head, int k) {
    // Write your code here
    Node *temp = head;

    while(temp != nullptr){
        if(temp->data == k){
            Node *delNode = temp;
            if(delNode == head){
                if(delNode->next == nullptr) return nullptr;
                delNode->next->prev = nullptr;
                temp = delNode->next;
                head = temp;
                delete delNode;
            }else if(delNode->next == nullptr){
                delNode->prev->next = nullptr;
                temp = delNode->next;
                delete delNode;
            }else{
                delNode->prev->next = delNode->next;
                delNode->next->prev = delNode->prev;
                temp = delNode->next;
                delete delNode;
            }
        }else{
            temp = temp->next;
        }
    }
    return head;
}