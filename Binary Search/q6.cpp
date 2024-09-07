#include <iostream>
#include <vector>


int minVal(std::vector <int> arr){
    int low = 0;
    int n = arr.size();
    int high = n-1;
    int ans = INT32_MAX;

    while(low <= high){
        int mid = (low + high)/2;
        //edge Case
        if(arr[mid] == arr[low] && arr[mid] == arr[high]){
            low += 1;
            high -= 1;
            continue;
        }
        // left side sorted
        if(arr[mid] >= arr[low]){
            if(arr[low] < ans) ans = arr[low];
            low = mid + 1;
        }
        //right side sorted
        if(arr[mid] <= arr[high]){
            if(arr[mid] < ans) ans = arr[mid];
            high = mid - 1;
        }
    }
    return ans;
}

int main(){

    std::vector<int> vec = {3,3,1,3,3,3,3};
    std::cout<<minVal(vec);


    return 0;
}