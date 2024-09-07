#include<iostream>
#include<vector>


void createSequenceHelper(long long current, long long n, std::vector<long long> &result){
    
    // Base case.
    if(current > n) {
        return ;
    }
        

    // Add the current number to result.
    if(current != 0) {
        result.push_back(current);
    }

    // Recurse by adding 2 and 5 to the end of the number
    createSequenceHelper(current * 10  + 2, n, result);
    createSequenceHelper(current * 10 + 5, n, result);
}

int main(){
    long long n = 30;
    std::vector<long long > ans;
    createSequenceHelper(0,n,ans);
    for(int i: ans){
        std::cout<<i<<" ";
    }

    return 0;
}