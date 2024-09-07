#include <iostream>
#include <vector>
#include <map>
int main(){
    int n;
    std::cin>>n;
    std::vector <int> arr;
    int k;
    std::cin>>k;
    for(int i{} ; i<n ; i++){
        int temp;
        std::cin>>temp;
        arr.push_back(temp);
    }
    int counter{};
    std::map<long long , int> preSums;
    preSums[0] = 1;
    long long sum = 0;
    for(int i{} ; i<n ; i++){
        sum+=arr.at(i);
        preSums[sum]++;
        if(preSums.count(sum-k)){
            counter+=preSums.at(sum-k);
        }
    }
    std::cout<<counter;
    return 0;
}