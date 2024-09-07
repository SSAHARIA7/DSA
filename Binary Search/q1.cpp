#include <iostream>
#include <vector>


int lowerBound(std::vector<int> arr, int n, int target) {
    int low = 0;
    int high = n-1;
    int mid = (low + high)/2;
    int index{arr.size()};

    while(low <= high){
        mid = (low + high)/2;
        if(arr[mid] >= target){
            high = mid -1;
            index = mid;
        }else {
            low = mid + 1;
        }
    }
    return index;
}

int main(){
    std::vector<int> vec {1,2,4,7,9};
    std::cout<<lowerBound(vec,vec.size(),3);
    return 0;
}