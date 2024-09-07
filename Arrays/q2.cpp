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


    
    int largest = arr.at(0);
    int sLargest = INT32_MIN;
    for(int i: arr){
        if(i>largest){
            sLargest = largest;
            largest = i;
        }else if(i>sLargest && i<largest){
            sLargest = i;
        }
    }
    std::cout<<sLargest;
    return 0;
}