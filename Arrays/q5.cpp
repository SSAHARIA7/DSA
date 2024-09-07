#include <iostream>
#include <vector>
int main(){
    int n;
    std::cin>>n;
    std::vector <int> arr;
    for(int i{} ; i<n ; i++){
        int temp;
        std::cin>>temp;
        arr.push_back(temp);
    }
    int temp = arr.at(0);
    for(int i{1} ; i<n ; i++){
        arr.at(i-1) = arr.at(i);
    }
    arr.at(n-1) = temp;
    for(int i: arr){
        std::cout<<i<<" ";
    }
    return 0;
}