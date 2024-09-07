#include <iostream>
#include <vector>
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


  std::vector<std::pair<int, int>> findPairs(Node* head, int k)
{
    Node *left = head;
    Node *right = head;
    std::vector<std::pair<int,int>> ans;
    while(right->next != nullptr){
        right = right->next;
    }

    while(left!=right && right->next != left){
        if(left->data + right->data == k){
            ans.push_back(std::make_pair(left->data,right->data));
            left = left->next;
            right = right->prev;
        }else if(left->data + right->data > k){
            right = right->prev;
        }else{
            left = left->next;
        }
    }
    return ans;

}