#include <iostream>
#include <vector>
#include <algorithm>
int aggressiveCows(std::vector<int> &stalls, int k)
{
    std::sort(stalls.begin(),stalls.end());
    int low = 1;
    int high = stalls.at(stalls.size()-1);
    int maxLeastDist{INT32_MIN};
    while(low<=high){
        int leastDist{INT32_MAX};
        int mid = (low + high)/2;
        int tempCows = k;
        int prevCow{};
        for(int i{} ; i<stalls.size() ; i++){

            if(i==0){
                tempCows--;

            }else{

                if(stalls.at(i) - stalls.at(prevCow) >= mid){
                    tempCows--;
                    leastDist = std::min(leastDist,stalls.at(i)-stalls.at(prevCow));
                    prevCow = i;
                }

                if(tempCows == 0){
                    break;
                }
            }
        }            
        if(tempCows==0){
            maxLeastDist = std::max(leastDist,maxLeastDist);
            low = mid + 1;
        }else{
            high = mid-1;
        }


    }

    return maxLeastDist;
}

int main(){

    std::vector <int> arr;
    int n;
    std::cin>>n;
    int k;
    std::cin>>k;
    for(int i{} ; i<n ; i++){
        int temp;
        std::cin>>temp;
        arr.push_back(temp);
    }
    std::cout<<aggressiveCows(arr,k);
    return 0;
}