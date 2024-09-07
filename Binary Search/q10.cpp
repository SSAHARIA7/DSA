#include <iostream>

int NthRoot(int n, int m) {
    int low = 1;
    int high = m;
    while (low <= high){
        long long mid = (low + high)/2;
        long long val{1};
        for(int i{1} ; i<= n ; i++){
          val*=mid;
          if(val > m){
            high = mid - 1;
            break;
          }  
        }   
        if(val == m) return mid;
        if(val < m) {
            low = mid + 1;
        }
    }
    return -1;
}

int main(){
    std::cout<<NthRoot(4,10000);
    return 0;
}