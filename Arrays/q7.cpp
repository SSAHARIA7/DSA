#include <iostream>
#include <vector>
void swap(int &a , int &b){
    int temp = a;
    a = b;
    b= temp;
}
int main(){
    int n;
    std::cin>>n;
    std::vector <int> arr;
    for(int i{} ; i<n ; i++){
        int temp;
        std::cin>>temp;
        arr.push_back(temp);
    }
    int counter = 0;
    for(int i{} ; i<n-1 ; i++){
        if(arr.at(i) == 0){
            if(arr.at(i+1) != 0){
                swap(arr.at(i+1),arr.at(i-counter));
            }else{
                counter++;
            }
        } 
    }


    for(int i: arr){
        std::cout<<i<<" ";
    }
    return 0;
}