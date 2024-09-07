#include <iostream>
#include <vector>


int searchInsert(std::vector<int>& arr, int target)
{
    int n = arr.size();
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

    std::vector <int> arr = {1, 2, 4, 7};
    std::cout<<searchInsert(arr,6);
    return 0;
}