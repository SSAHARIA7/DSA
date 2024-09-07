#include <iostream>

class Node {
  public:
       int data;
       Node *next;
       Node() {
           this->data = 0;
           this->next = NULL;
       }
       Node(int data) {
           this->data = data;
           this->next = NULL;
       }
       Node (int data, Node *next) {
           this->data = data;
          this->next = next;
       }
  };



Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node *answerHead = nullptr; 
    Node *prev = nullptr;
    
    int carry{};
    while(num1 != nullptr || num2 != nullptr){
        int sum{};
        if(num1 == nullptr && num2 != nullptr){
            sum = num2->data + carry;
        }else if(num1 != nullptr && num2 == nullptr){
            sum = num1->data + carry;
        }else{
         sum = num1->data + num2->data + carry;
        }
        if(sum > 9){
            carry = 1;
            sum = sum%10;
        }else{
            carry = 0;
        }
        Node *temp = new Node(sum);
        if(prev != nullptr){
            prev->next = temp;
        }
        prev = temp;

        if(answerHead == nullptr){
            answerHead = temp;
        }
        if(num1 != nullptr){
            num1 = num1 ->next;
        }
        if(num2 != nullptr){
            num2 = num2 -> next;
        }
    }

    if(carry == 1){
        Node *temp = new Node(1);
        prev->next = temp;
        prev = temp;
    }
    return answerHead;
}

void printLL(Node *head){

    while(head != nullptr){
        std::cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){


    return 0;
}