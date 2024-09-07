#include <iostream>
#include <vector>
#include <deque>
int main(){
    int n;
    std::cin>>n;
    std::vector <int> arr;
    for(int i{} ; i<n ; i++){
        int temp;
        std::cin>>temp;
        arr.push_back(temp);
    }
    int maxRight = INT32_MIN;
    std:: deque<int> leaders;
    for(int i{n-1} ; i >= 0; i--){
        if(arr.at(i) > maxRight){
            leaders.push_front(arr.at(i));
            maxRight = arr.at(i);
        }
    }

    for(int i: leaders){
        std::cout<<i<<" ";
    }
    return 0;
}