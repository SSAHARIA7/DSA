#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
int leastWeightCapacity(std::vector<int> &weights, int d){

    int low = *std::max_element(weights.begin(),weights.end());
    int high = std::accumulate(weights.begin(),weights.end(),0);
    int leastWtCap{INT32_MAX};
    while(low <= high){
        int tempDays{};
        int mid = (low + high)/2;
        int tempWeight = mid;
        for(int i: weights){
            if(i<=tempWeight){
                tempWeight -= i;
            }else{
                tempDays++;
                tempWeight = mid;
                tempWeight -= i;
            }
        }
        tempDays++;
        if(tempDays <= d){
            leastWtCap = std::min(leastWtCap,mid);
            high= mid -1;
        }else{
            low = mid + 1;
        }

    }

    return leastWtCap;

}


int main(){
    std::vector <int> arr;
    int n;
    std::cin>>n;
    int d;
    std::cin>>d;
    for(int i{} ; i<n ; i++){
        int temp;
        std::cin>>temp;
        arr.push_back(temp);
    }

    std::cout<<leastWeightCapacity(arr,d);

    return 0;
}