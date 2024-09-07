#include <iostream>
#include <vector>
#include <unordered_set>

int main(){
    int n;
    std::cin>>n;
    std::vector <int> a;
    for(int i{} ; i<n ; i++){
        int temp;
        std::cin>>temp;
        a.push_back(temp);
    }

    int longest = 1;
    std::unordered_set<int> st;
    //put all the array elements into set:
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
    }

    //Find the longest sequence:
    for (auto it : st) {
        //if 'it' is a starting number:
        if (st.find(it - 1) == st.end()) {
            //find consecutive numbers:
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = std::max(longest, cnt);
        }
    }
    std::cout<<longest;
    return 0;
}