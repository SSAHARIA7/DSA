#include<iostream>
#include<vector>
#include <algorithm>
void combinationSum2(std::vector<int> &arr, int target, std::vector<int> &storageArr, int start, std::vector<std::vector<int>> &ans){

    if(start>=arr.size()){
        if(target==0){
            ans.push_back(storageArr);
        }
        return;
    }

    if(target<0){
        return;
    }

    int  duplicates = 0;
    while(start < arr.size()-1 && arr.at(start) == arr.at(start+1)){
        start++;
        duplicates++;
    }

    for(int i{} ; i<=duplicates ; i++){
        storageArr.push_back(arr.at(start));
        target-= arr.at(start);
        combinationSum2(arr,target,storageArr,start+1,ans);
    }

    for(int i{} ; i<=duplicates ; i++){
        storageArr.pop_back();
        target+= arr.at(start);
    }
    combinationSum2(arr,target,storageArr,start+1,ans);
}



int main(){
    std::vector<int> arr = {10,1,2,7,6,1,5};
    std::sort(arr.begin(),arr.end());
    std::vector<int> temp;
    std::vector <std::vector<int>> ans;
    combinationSum2(arr,8,temp,0,ans);
    for(auto v: ans){
        for(int i: v){
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}