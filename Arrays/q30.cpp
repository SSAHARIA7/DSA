#include <iostream>
#include <vector>
#include <algorithm>
int main(){
    int n;
    std::cin>>n;
    int target;
    std::cin>>target;
    std::vector <int> arr;
    for(int i{} ; i<n ; i++){
        int temp;
        std::cin>>temp;
        arr.push_back(temp);
    }
    std::sort(arr.begin(),arr.end());
    std::vector <std::vector<int>> quads;
    for(int i{} ; i < n ; i++){
        if(i>0 && arr.at(i) == arr.at(i-1)){
            continue;
        }
        for(int j{i+1} ; j < n ; j++){
            if(j>i+1 && arr.at(j) == arr.at(j-1)){
                continue;
            }
            int rightMover = j+1;
            int leftMover = n -1 ;
            while(leftMover > rightMover){
                int sum = arr.at(i) + arr.at(j) + arr.at(rightMover) + arr.at(leftMover);
                if(sum == target){
                    std::vector <int> temp = {arr.at(i),arr.at(j),arr.at(rightMover),arr.at(leftMover)};
                    quads.push_back(temp);
                    rightMover++;
                    leftMover--;
                    while(rightMover<leftMover && arr.at(rightMover) == arr.at(rightMover-1)){
                        rightMover++;
                    }
                    while(leftMover > rightMover && arr.at(leftMover) == arr.at(leftMover+1)){
                        leftMover--;
                    }
                }else if(sum>target){
                    leftMover--;
                }else{
                    rightMover++;
                }
            }
         }
    }
    std::cout<<"Number of Quads: "<<quads.size()<<std::endl;
    for(int i{} ; i<quads.size() ; i++){
        for(int j{} ; j<4 ; j++){
            std::cout<<quads.at(i).at(j)<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}