#include <iostream>
#include <stack>
#include <vector>


std::vector < int > nextSmallerElements(std::vector < int > & nums) {
      int n = nums.size();
      std::vector < int > nse(n);
      std::stack < int > st;
      for (int i =  n - 1; i >= 0; i--) {
        while (!st.empty() && nums.at(st.top()) > nums.at(i)) {
          st.pop();
        }

        if(st.empty()){
            nse.at(i) = n;
            st.push(i);
        }else{
            nse.at(i) = st.top();
            st.push(i);
        }

      }
      return nse;
    }


std::vector <int> prevSmallerElements(std::vector<int> &nums){
    std::stack<int> st;
    std::vector<int> ans;
    for(int i{} ; i<nums.size() ; i++){

            while(!st.empty() && nums.at(st.top()) >= nums.at(i)){
                st.pop();
            }


            if(st.empty()){
                ans.push_back(-1);
            }else{
                ans.push_back(st.top());
            }
            st.push(i);
        }
       return ans;
    }


int sumSubarrayMins(std::vector<int>& arr) {
        std::vector<int> prevSmaller = prevSmallerElements(arr);
        std::vector<int> nextSmaller = nextSmallerElements(arr);
        int ans{};
        for(int i{} ; i<arr.size() ; i++){
            int left{i-prevSmaller.at(i)},right{nextSmaller.at(i) - 1};
            ans += (right*left*1LL*arr.at(i))%(int)(1e9 + 7);
        }

        return ans;


    }



int main(){
    std::vector<int> arr = {3,1,2,4};
    std::vector<int> prevSmaller = prevSmallerElements(arr);
        std::vector<int> nextSmaller = nextSmallerElements(arr);

    for(int i: nextSmaller){
        std::cout<<i<<" ";
    }
    return 0;
}