# include<iostream>

int main(){
     int n; 
    std::cin>>n;
    int arr[n];
    for(int i{} ; i<n ; i++){
        std::cin>>arr[i];
    }    

    for(int i{1} ; i<n ; i++){
        int temp = arr[i];
        int j{i-1};
        for( ; j >= 0 ; j--){
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }else{
                break;
            }
        }
        arr[j+1]  = temp;
    }

    for(int i: arr){
        std::cout<<i<<" ";
    }
     return 0;
}