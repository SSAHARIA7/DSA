#include <iostream>
#include <vector>

void combinationSum1(std::vector<int> &arr,int start,std::vector<int> &storageArr,int target,int currentSum,std::vector<std::vector<int>> &ans){

        if(start >= arr.size()){
            if(currentSum==target){
                ans.push_back(storageArr);
            }
            return;
        }

        if(currentSum>target){
            return;
        }

    int choices = target/arr.at(start);

    for(int i{} ; i<choices ; i++){
        storageArr.push_back(arr.at(start));
        currentSum+=arr.at(start);
        combinationSum1(arr,start+1,storageArr,target,currentSum,ans);
    }
    for(int i{} ; i<choices ; i++){
        storageArr.pop_back();
        currentSum-=arr.at(start);
    }
    combinationSum1(arr,start+1,storageArr,target,currentSum,ans);
}




int main(){
    std::vector<int> arr = {2};

    std::vector<std::vector<int>> ans;

    std::vector<int> temp;

    int target = 1;

    combinationSum1(arr,0,temp,target,0,ans);

    for(auto v: ans){
        for(int i: v){
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;
    }
    

    return 0;
}