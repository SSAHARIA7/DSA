#include<iostream>

void BSIterative(int n, int arr[], int target){
    int low = 0;
    int high = n-1;
    int mid = (low + high)/2;

    while(low <= high){
        mid = (low + high)/2;
        if(arr[mid] > target){
            high = mid -1;
        }else if(arr[mid] < target){
            low  = mid + 1;
        }else{
            std::cout<<target<<" found at "<<mid<<" index"<<std::endl;
            return;
        }
    }
    std::cout<<"Not Found"<<std::endl;
    return;

}

void BSRecursive(int low , int high,int arr[], int target){
    int mid = (low + high)/2;
    if(arr[mid] == target){
        std::cout<<target<<" found at "<<mid<<" index"<<std::endl;
        return;
    }
    if(low > high){
        std::cout<<"Not Found"<<std::endl;
        return;
    }
    if(arr[mid] > target){
        BSRecursive(low,mid-1,arr,target);
    }else if(arr[mid] < target){
        BSRecursive(mid+1,high,arr,target);
    }
}

int main(){

    int arr[] = {1,3,4,7,9,12,15,16};
    BSIterative(8,arr,12);
    BSRecursive(0,7,arr,12);
    return 0;
}