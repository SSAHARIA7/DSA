#include <iostream>
#include <vector>
#include <map>
int main(){
    int n;
    std::cin>>n;
    std::vector <int> arr;
    for(int i{} ; i<n ; i++){
        int temp;
        std::cin>>temp;
        arr.push_back(temp);
    }
    int k;
    std::cin>>k;
    int maxSize = 0;
    std::map<long long , int> preSums;
    preSums[0] = -1;
    int sum = 0;
    for(int i{} ; i<n ; i++){
        sum+=arr.at(i);
        if(!preSums.count(sum)){
            preSums[sum] = i;
        }
        if(preSums.count(sum-k)){
            if(maxSize < i - preSums.at(sum-k)){
                maxSize = i-preSums.at(sum-k);
            }
        }
    }
    std::cout<<maxSize;
    return 0;
}