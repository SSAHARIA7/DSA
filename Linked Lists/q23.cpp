#include <iostream>



  class Node {
   public:
 		int data;
 		Node *next;
  		Node *random;
 		Node() : data(0), next(nullptr), random(nullptr){};
 		Node(int x) : data(x), next(nullptr), random(nullptr) {}
 		Node(int x, Node *next, Node *random) : data(x), next(next), random(random) {}
  };




  Node *cloneLL(Node *head){

    Node *temp = head;

    while(temp != nullptr){
        Node *newNode = new Node(temp->data);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = temp->next->next;
    }

    temp = head;

    while(temp != nullptr){
        if(temp->random == nullptr){
            temp->next->random = nullptr;
        }else{
            temp->next->random = temp->random->next;
        }
        temp = temp->next->next;
    }


    Node *dummyNode = new Node(-1); 
    Node *tempDummy = dummyNode;
    temp = head;
    while(temp != nullptr){
        tempDummy->next = temp->next;
        temp->next = temp->next->next;
        tempDummy = tempDummy->next;
        temp = temp->next;
    }
    return dummyNode->next;
}