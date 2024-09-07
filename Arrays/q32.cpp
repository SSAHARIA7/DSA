#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
int main(){
    int n;
    std::cin>>n;
    std::vector <std::vector<int>> arr;
    for(int i{} ; i<n ; i++){
        std::vector<int> temp;
        for(int i{} ; i<2 ;i++){
            int j;
            std::cin>>j;
            temp.push_back(j);
        }
        arr.push_back(temp);
    }
    std::vector<std::vector<int>> mergedIntervals;
    std::sort(arr.begin(),arr.end());
    int open = arr.at(0).at(0);
    int close = arr.at(0).at(1);
    for(int i{1} ; i<n ; i++){
        if(arr.at(i).at(0) <= close){
            if(arr.at(i).at(1) > close){
                close = arr.at(i).at(1);
            }
        }else{
            mergedIntervals.push_back({open,close});
            open = arr.at(i).at(0);
            close = arr.at(i).at(1);       
        }
    }
    mergedIntervals.push_back({open,close});

    for(int i{} ; i<mergedIntervals.size() ; i++){
        std::cout<<mergedIntervals.at(i).at(0)<<" "<<mergedIntervals.at(i).at(1)<<std::endl;
    }


    return 0;
}