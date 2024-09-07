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
    int max = INT32_MIN;
    for(auto i : arr){
        if(i>max){
            max = i;
        }
    }
    std::cout<<max<<std::endl;


    return 0;
}