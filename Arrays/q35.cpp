#include <iostream>
#include <vector>
#include <algorithm>

int counter;

void merge(int *arr, int start , int end){
    int mid = (start+end)/2;
    int  len1 = mid -start + 1;
    int len2 = end - mid;
    int *first = new int[len1];
    int *second = new int[len2];
    int count{};
    int mainArrayIndex = start;
    for(int i{} ; i < len1 ; i++){
        first[i] = arr[mainArrayIndex++];
    }
    mainArrayIndex = mid+1;
    for(int i{} ; i < len2 ; i++){
        second[i] = arr[mainArrayIndex++];
    }

    int index1 = 0 ;
    int index2 = 0 ; 
    mainArrayIndex = start;
    //Merge 2 Sorted Arrays

    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            arr[mainArrayIndex++] = first[index1++];
        }else{
            counter+=len1-index1;  //COUNTER
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while(index1 < len1){
        arr[mainArrayIndex++] = first[index1++];

    }
    while(index2 < len2){
        arr[mainArrayIndex++] = second[index2++];
        
    }
    delete []first;
    delete []second;

}



void mergeSort(int *arr, int start , int end){
    static int counter = 0;
    if(start>=end){
        return ;
    }
    int mid = (start+end)/2;

    mergeSort(arr,start,mid);

    mergeSort(arr,mid+1,end);

    merge(arr,start,end);

}
int main(){
    int n;
    std::cin>>n;
    int arr[n];
    for(int i{} ; i<n ; i++){
        std::cin>>arr[(i)];
    }



    mergeSort(arr,0,n-1);
    std::cout<<counter;
    
    // for(int i{} ; i<n ; i++){
    //     std::cout<<arr[i]<<" ";
    // }
    return 0;
}