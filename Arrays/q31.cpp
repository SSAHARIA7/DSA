#include <iostream>
#include <vector>
#include <algorithm>
#include<map>
int main(){
    int n;
    std::cin>>n;
    std::vector <int> arr;
    int k;
    std::cin>>k;
    for(int i{} ; i<n ; i++){
        int temp;
        std::cin>>temp;
        arr.push_back(temp);
    }
    std::map<int,int> mp;
    mp[0] = 1;
    int xr{};
    int ans{};
    for(int i{} ; i<n ; i++){
        xr ^= arr.at(i);
        mp[xr]++;
        if(mp.find(xr^k) != mp.end()){
            ans += mp.at(xr^k);
        }
    }

    std::cout<<ans;
    return 0;
}