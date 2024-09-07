#include <iostream>
#include <vector>
#include <algorithm>
void findSubsets(int i,std::vector<int> &arr,std::vector<std::vector<int>> &powerSet,std::vector<int> &subSet){
    
    if(i==arr.size()){
        powerSet.push_back(subSet);
        return;
    }

    //pick
    subSet.push_back(arr.at(i));
    findSubsets(i+1,arr,powerSet,subSet);
    subSet.pop_back();
    //skip
    while(i+1 < arr.size() && arr.at(i) == arr.at(i+1)){
        i++;
    }
    findSubsets(i+1,arr,powerSet,subSet);


}


int main(){
    std::vector<int> arr{1,2,2};
    std::sort(arr.begin(),arr.end());
    std::vector<std::vector<int>> powSet;
    std::vector<int> subset;
    findSubsets(0,arr,powSet,subset);
    for(auto v: powSet){
        for(int i: v){
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;
    }


    return 0;
}