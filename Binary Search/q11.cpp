#include <iostream>
#include <vector>

int minimumRateToEatBananas(std::vector<int> v, int h) {
    // Write Your Code Here
    int maxBananas{};
    for(int i: v){
        if(maxBananas < i){
            maxBananas = i;
        }
    }
    int low {1} , high{maxBananas};
    int minBananas{INT32_MAX};
    while(low<=high){
        int tempHours{};
        int mid = (low + high)/2;
        for(int i : v){
            if(i % mid == 0){
                tempHours += (i/mid);
            }else{
                tempHours += ((i/mid) + 1);
            }
        }

        if(tempHours <= h){
            minBananas = std::min(minBananas,mid);
            high = mid - 1;
        }else{
            low = mid + 1;
        }

    }

    return minBananas;
}

int main(){
    std::vector<int> arr = {7,15,6,3};
    std::cout<<minimumRateToEatBananas(arr,8);

    return 0;
}