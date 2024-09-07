#include <iostream>
#include <vector>
#include <algorithm>
int main(){
    int n;
    std::cin>>n;
    std::vector <int> arr;
    for(int i{} ; i<n ; i++){
        int temp;
        std::cin>>temp;
        arr.push_back(temp);
    }

    int d; 
    std::cin>>d;
    std::reverse(arr.begin() , arr.begin() + d);
    std::reverse(arr.begin() + d , arr.end());
    std::reverse(arr.begin() , arr.end());


    for(int i: arr){
        std::cout<<i<<" ";
    }
    return 0;
}