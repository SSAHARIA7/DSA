#include <iostream>
#include <vector>
#include <algorithm>
int main(){
    int n;
    std::cin>>n;
    std::vector <int> arr;
    for(int i{} ; i<n ; i++){
        int temp;
        std::cin>>temp;
        arr.push_back(temp);
    }

    std::sort(arr.begin(), arr.end());
    std::vector<std::vector<int>> triplets;

    int left{0};
  
    std::vector <int> tempTriplet;

    while(left < n){
        if(left > 0 && arr.at(left) == arr.at(left-1)){
            left++;
            continue;

        }
        int middle = left+1;
        int right  = n-1;
        while(middle < right){
            int sum = arr.at(left) + arr.at(middle) + arr.at(right) ;
            if(sum == 0){
                std::vector <int> tempTriplet = {arr.at(left),arr.at(middle),arr.at(right)};
                triplets.push_back(tempTriplet);
                    middle++;
                    right--;
                while(middle < right && arr.at(middle) == arr.at(middle-1)){
                    middle++;
                }
                while(middle < right && arr.at(right) == arr.at(right+1)){
                    right--;
                }
            }else if(sum > 0){
                right--;
            }else{
                middle++;
            }
        }
        left++;
    }





    for(int i{} ; i<triplets.size() ; i++){
        for(int j{} ; j<3 ; j++){
            std::cout<<triplets.at(i).at(j)<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}