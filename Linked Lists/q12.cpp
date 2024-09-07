#include <iostream>

class Node {
  public:
       int data;
       Node *next;
 
       Node(int data) {
           this->data = data;
           this->next = NULL;
       }
  };

    bool detectCycle(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    while(fast->next != nullptr && fast->next->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            return true;
        }
    }
    return false;
}
int lengthOfLoop(Node *head) {
    Node *fast = head;
    Node *slow = head;
    bool loop = false;
    while(fast->next != nullptr && fast->next->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            loop = true;
            break;
        }
    }

    if(!loop) return 0;
    int counter = 1;
    slow = slow->next;
    while(slow != fast){
        counter++;
        slow = slow->next;
    }

    return counter;
    


}
