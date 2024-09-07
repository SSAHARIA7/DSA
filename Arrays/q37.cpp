#include <iostream>
#include <vector>
#include <algorithm>





int main(){
    int n;
    std::cin>>n;
    std::vector <int> arr;
    for(int i{} ; i<n ; i++){
        int temp;
        std::cin>>temp;
        arr.push_back(temp);
    }

    int pre = 1, suff = 1;
    int ans = INT32_MIN;
    for (int i = 0; i < n; i++) {
        if (pre == 0) pre = 1;
        if (suff == 0) suff = 1;
        pre *= arr[i];
        suff *= arr[n - i - 1];
        ans = std::max(ans, std::max(pre, suff));
    }
    std::cout<<ans;
    return 0;
}