#include <iostream>
#include <vector>

void uniqueSubsets(std::vector<int> &arr, std::vector<int> &storageArr, std::vector<std::vector<int>> &ans, int start){
    
    if(start == arr.size()){
        ans.push_back(storageArr);
        return;
    }
    
    int  duplicates = 0;
    while(start < arr.size()-1 && arr.at(start) == arr.at(start+1)){
        start++;
        duplicates++;
    }

    for(int i{} ; i<=duplicates ; i++){
        storageArr.push_back(arr.at(start));
        uniqueSubsets(arr,storageArr,ans,start+1);
    }
    for(int i{} ; i<=duplicates ; i++){
        storageArr.pop_back();
    }
    uniqueSubsets(arr,storageArr,ans,start+1);

}

int main(){

    std::vector<int> arr = {1,2,2};
    std::vector<int> temp;
    std::vector<std::vector<int>> ans;

    uniqueSubsets(arr,temp,ans,0);

    for(auto v: ans){
        for(int i: v){
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;
    }


    return 0;
}