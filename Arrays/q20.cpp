#include <iostream>
#include <vector>
#include <algorithm>
void swap(int &a , int &b){
    int temp = a; 
    a = b;
    b = temp;
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


   // std::next_permutation(arr.begin(),arr.end());
        int changeNumber{};
        int changeIndex{-1};
        for(int i{n-2} ; i>=0 ; i--){
            if(arr.at(i) < arr.at(i+1)){
                changeNumber = arr.at(i);
                changeIndex = i;
                break;
            }
        }
    if(changeIndex == -1){
        std::reverse(arr.begin(), arr.end());
    }else{

        for(int i{n-1} ; i>changeIndex ; i--){
            if(arr.at(i) > arr.at(changeIndex)){
                swap(arr.at(changeIndex) , arr.at(i));
                break;
            }
        }

        std::reverse(arr.begin() + changeIndex + 1,arr.end());
    }

    for(int i: arr){
        std::cout<<i<<" ";
    }
    return 0;
}