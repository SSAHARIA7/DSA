#include <iostream>
int floorSqrt(int n)
{
    int low = 0;
    int high = n;
    int ans;
    while (low <= high){
        long long mid = (low + high)/2;
        long long val = mid*mid;
        if(val > n) high = mid - 1;
        if(val == n) return mid;
        if(val < n) {
            ans = mid;
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    std::cout<<floorSqrt(28);
    return 0;
}