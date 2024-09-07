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
    int k;
    std::cin>>k;
    int left{},right{};
    long long sum  = 0;
    int maxSize = 0;
    while(right < n){
        sum += arr.at(right);
        while(right >= left && sum > k){
            sum -= arr.at(left);
            left++;
        }
        if(sum == k){
            if(right-left+1 > maxSize){
                maxSize = right-left+1;
            }
        }
        right++;
    }
    std::cout<<maxSize;

    return 0;
}