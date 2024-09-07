#include <iostream>
#include <vector>
#include <algorithm>

int factorial(int n){
    if(n==1){
        return 1;
    }
    return n*factorial(n-1);
}

int main(){
    long long n;
    std::cin>>n;
    std::vector <int> arr;
    for(int i{} ; i<n ; i++){
        int temp;
        std::cin>>temp;
        arr.push_back(temp);
    }

    long long expectedSum{(n*(n+1))/2};
    long long expectedSum2{(n*(n+1)*(2*n+1))/6};
    long long sum{};
    long long sum2{};

    for(int i{} ; i<n ; i++){
        sum+=arr.at(i);
        sum2+=arr.at(i)*arr.at(i);
    }
    int difference{};
    int difference2{};
    int missing{},extra{};
    std::vector <int> ans;
    difference = sum - expectedSum;
    difference2 = sum2 - expectedSum2;
    extra = (difference + (difference2/difference))/2;
    missing = extra - difference;



    ans.push_back(extra);;
    ans.push_back(missing);

    for(int i: ans){
        std::cout<<i<<" ";
    }
    return 0;
}