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
    bool sorted = true;
    for(int i{1} ; i<n ; i++){
        if(arr.at(i) < arr.at(i-1)){
            sorted = false;
        }
    }
    std::cout<<std::boolalpha;
    std::cout<<sorted;
    return 0;
}