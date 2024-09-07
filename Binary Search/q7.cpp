#include <iostream>
#include <vector>


int singleElement(std::vector<int> arr){

    int low = 0;
    int  high = arr.size() - 1;

    while (low <= high){
        int mid = (low + high)/2;

        if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]){
            return arr[mid];
        }

        if(arr[mid] == arr[mid + 1]){
            if(mid % 2 == 0){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        if(arr[mid] == arr[mid -1]){
            if(mid %2 == 0){
                high = mid -1;
            }else {
                low = mid + 1;
            }
        }
    }
}



int main(){
    std::vector<int> arr = {1 ,1, 4 ,4 ,15};
    std::cout<<singleElement(arr);

    return 0;
}