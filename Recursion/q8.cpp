#include<iostream>
#include<vector>

void helper(int n,int k , std::vector<int> &ans){
    //baseCase
    if(n<=0){
        ans.push_back((n));
        return;
    }

    //smallWork
    ans.push_back(n);
    helper(n-k,k,ans);
    ans.push_back(n);
}


int main(){
    std::vector<int> ans;
    int n  = 5;
    int k = 2;
    helper(n,k,ans);

    for(int i : ans){
        std::cout<<i<<" ";
    }
    return 0;
}