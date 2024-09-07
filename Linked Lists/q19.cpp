#include <iostream>


class Node {
  public:
      int data;
      Node *next;
      Node() : data(0), next(nullptr) {}
      Node(int x) : data(x), next(nullptr) {}
      Node(int x, Node *next) : data(x), next(next) {}
  };









Node *rotate(Node *head, int k) {
    Node *temp = head;
    int n = 1;
    while(temp->next != nullptr){
        n++;
        temp  = temp->next;
    }
    if(k>=n) k = k%n;
    k = n-k;
    temp->next = head;
    while(k){
        temp = temp->next;
        k--;
    }
    head = temp->next;
    temp->next = nullptr;
    return head;
}