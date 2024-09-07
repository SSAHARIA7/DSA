#include <iostream>
#include <algorithm>
#include  <vector>

int editedLowerBound(std::vector<int> arr, int n, int target) {
    int low = 0;
    int high = n-1;
    int mid = (low + high)/2;
    int index{-1};

    while(low <= high){
        mid = (low + high)/2;
        if(arr[mid] == target){
            high = mid -1;
            index = mid;
        }else if(arr[mid] > target){
            high = mid -1;
        }else {
            low = mid + 1;
        }
    }
    return index;
}

int editedUpperBound(std::vector<int> arr, int n ,int target){
    int high = n-1;
    int low = 0;
    int mid = (low + high)/2;
    int index = -1;

    while(low <= high){
        mid = (low + high)/2;
        if(arr[mid] < target){
            low = mid + 1;
        }else if(arr[mid] == target){
            low = mid + 1;
            index = mid;
        }else{
            high = mid -1;
        }
    }
    return index;
}

int main(){

    std::vector<int> v = {0,0,1,1,2,2,2,2};

    int firstOccurence = editedLowerBound(v,v.size(),2);
    int lastOccurence =  editedUpperBound(v,v.size(),2) ;


    std::cout<<firstOccurence<<std::endl;
    std::cout<<lastOccurence;
    return 0;
}