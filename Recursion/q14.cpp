#include <iostream>
#include <vector>

void subsetSum1(std::vector<int> &arr, int sum , int start, std::vector<int> &ans){

    if(start>=arr.size()){
        ans.push_back(sum);
        return;
    }



    sum += arr.at(start);
    subsetSum1(arr,sum,start+1,ans);
    sum-= arr.at(start);
    subsetSum1(arr,sum,start+1,ans);



}


int main(){

    std::vector<int> arr = {2,3};
    std::vector<int> ans;
    subsetSum1(arr,0,0,ans);

    for(int i: ans){
        std::cout<<i<<" ";
    }
    return 0;
}