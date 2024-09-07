# include<iostream>

int main(){
    int n;
    std::cin>>n;
    int arr[n];
    for(int i{} ; i < n ; i++){
        std::cin>>arr[i];
    }
    for(int i{} ; i < n-1 ; i++){
        int minIndex = i;
        for(int j{i+1}  ; j < n ; j++ ){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
    for(int i{} ; i<n ; i++){
        std::cout<<arr[i]<<" ";
    }

     return 0;
}