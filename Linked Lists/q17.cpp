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



  Node * removeDuplicates(Node *head)
{
    Node *temp = head;

    while(temp != nullptr){
        Node *delNodes = temp;
        
        while(temp->next != nullptr && temp->next->data == temp->data){
            temp = temp->next;
        }
        temp->prev = delNodes->prev;
        if(delNodes->prev != nullptr){
            delNodes->prev->next = temp;
        }
        if(temp->prev == nullptr) head = temp;
        while(delNodes != temp){
            Node *delNode = delNodes;
            delNodes = delNodes->next;
            delete delNode;
        }

        temp = temp->next;
    }

    return head;
}

