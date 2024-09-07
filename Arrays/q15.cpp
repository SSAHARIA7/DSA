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
    int target; 
    std::cin>>target;
    //FOR (ii) we have to use a map.
    //FOR (i) : 2 Pointer Approach 
    std::sort(arr.begin(),arr.end());
    int left = 0; 
    int right = n-1;
    while(right>left){
        if(arr.at(right) + arr.at(left) > target){
            right--;
        }else if(arr.at(right) + arr.at(left) < target){
            left++;
        }else{
            std::cout<<"YES";
            break;
        }
    }
    if(right<=left){
        std::cout<<"NO";
    }


    return 0;
}