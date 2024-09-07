#include<iostream>
#include <vector>
void swap(int &a , int &b){
    int temp = a; 
    a = b; 
    b= temp;
}
void reverseArrayHelper (std::vector<int> &arr , int start, int end ){
     	if(start>=end) return;
        swap(arr.at(start),arr.at(end));
        reverseArrayHelper(arr,start+1,end-1);
}

int main(){

    std::vector<int> arr {1,2,4,5,6,7};
    reverseArrayHelper(arr,3,5);
    for(int i: arr){
        std::cout<<i<<" ";
    }
    return 0;
}