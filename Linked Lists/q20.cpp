#include <iostream>


    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };


    Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    Node<int> *temp1 = first->data>second->data?second:first;
    Node<int> *temp2 = first->data>second->data?first:second;
    Node <int> *ans = temp1;
    while(temp1->next != nullptr){
        if(temp1->next->data <= temp2->data){
            temp1 = temp1->next;
        }else{
            Node <int> *temp = temp1->next;
            temp1->next = temp2;
            temp2 = temp;
            temp1 = temp1->next;
        }
    }
    if(temp2->next != nullptr) temp1->next = temp2;
    return ans;
}