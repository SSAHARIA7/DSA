# include<iostream>
void swap(int &a , int &b){
    int temp = a;
    a = b;
    b= temp;
}


int partition(int *arr , int start,int end){
    int pivot = arr[start];
    int count{};
    for(int i{start+1} ; i <= end ; i++){
        if(arr[i]  <=  pivot){
            count++;
        }
    }
    int pivotIndex= start+count;
    swap(arr[start] , arr[pivotIndex]);

    //handling left and right part

    int i{start},j{end};

    while(i < pivotIndex && j>pivotIndex){
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }

        if(i < pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int *arr, int start , int end){
    if(start>=end){
        return;
    }

    int p = partition(arr,start,end);
    quickSort(arr,start,p-1);
    quickSort(arr,p+1,end);
}


int main(){
     int arr[5] = {5,3,0,2,7};
     quickSort(arr,0,4);
     for(int i: arr){
        std::cout<<i<<" ";
     }
     return 0;
}