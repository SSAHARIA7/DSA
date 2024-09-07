#include <iostream>
#include <vector>


int smallestDivisor(std::vector<int>& arr, int limit)
{
	int high{};
    for(int i: arr){
        high = std::max(i,high);
    }
    int low = 1;
    int minDivisor{INT32_MAX};
    while(low <= high){
        int mid = (low + high)/2;
        int tempLim{};
        for(int i: arr){
            if(i%mid == 0){
                tempLim += (i/mid);
            }else{
                tempLim += (i/mid + 1);
            }
        }
        if(tempLim <= limit){
            high = mid -1;
            minDivisor = std::min(minDivisor,mid);
        }else{
            low = mid + 1;
        }
    }
    return minDivisor;
}


int main(){

    std::vector <int> arr;
    int n;
    std::cin>>n;
    for(int i{} ; i<n ; i++){
        int temp;
        std::cin>>temp;
        arr.push_back(temp);
    }
    int limit;
    std::cin>>limit;

    std::cout<<smallestDivisor(arr,limit);
    return 0; 
}