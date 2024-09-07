# include<iostream>

void swap(int &a , int &b){
    int temp = a;
    a = b; 
    b= temp;
}

int main(){
    int n; 
    std::cin>>n;
    int arr[n];
    for(int i{} ; i<n ; i++){
        std::cin>>arr[i];
    }     
    for(int i{} ; i < n-1 ; i++){
        int flag = 0;
        for(int j{} ; j < n-1-i ; j++){
            if(arr[j] > arr[j+1]){
                flag = 1;
                swap(arr[j] , arr[j+1]);
            }
        }
        if(flag==0){
            break;
        }
    }

    for(int i: arr){
        std::cout<<i<<" ";
    }

     return 0;
}