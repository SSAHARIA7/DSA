#include <iostream>

long long Pow(int X, int N){
    if(N==0) return 1;
    long long partialPow = Pow(X,N/2);
    if(N%2==0){
        return partialPow*partialPow;
    }else{
        return X*partialPow*partialPow;
    }
}



int main(){

    std::cout<<Pow(9,3);

    return 0;
}