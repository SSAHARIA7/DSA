#include <iostream>
#include <vector>
#include <stack>

std::vector < int > nextSmallerElements(std::vector < int > & nums) {
      int n = nums.size();
      std::vector < int > nse(n);
      std::stack < int > st;
      for (int i =  n - 1; i >= 0; i--) {
        while (!st.empty() && nums.at(st.top()) >= nums.at(i)) {
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


std::vector < int > nextGreaterElements(std::vector < int > & nums) {
      int n = nums.size();
      std::vector < int > nge(n);
      std::stack < int > st;
      for (int i =  n - 1; i >= 0; i--) {
        while (!st.empty() && nums.at(st.top()) <= nums.at(i)) {
          st.pop();
        }

        if(st.empty()){
            nge.at(i) = n;
            st.push(i);
        }else{
            nge.at(i) = st.top();
            st.push(i);
        }

      }
      return nge;
    }

std::vector <int> prevSmallerElements(std::vector<int> &nums){
    std::stack<int> st;
    std::vector<int> ans;
    for(int i{} ; i<nums.size() ; i++){

            while(!st.empty() && nums.at(st.top()) > nums.at(i)){
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


std::vector <int> prevgreaterElements(std::vector<int> &nums){
    std::stack<int> st;
    std::vector<int> ans;
    for(int i{} ; i<nums.size() ; i++){

            while(!st.empty() && nums.at(st.top()) < nums.at(i)){
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

    long long subArrayRanges(std::vector<int>& nums) {
        long long ans{};   
        std::vector<int> prevSmaller  = prevSmallerElements(nums);
        std::vector<int> nextSmaller = nextSmallerElements(nums);
        std::vector<int> nextGreater = nextGreaterElements(nums);
        std::vector<int> prevGreater = prevgreaterElements(nums);

        for(int i{} ; i<nums.size() ; i++){
            int smallRight = nextSmaller.at(i) - i;
            int smallLeft = i - prevSmaller.at(i);

            int greatRight = nextGreater.at(i) - i;
            int greatLeft = i - prevGreater.at(i);

            ans += (greatRight*greatLeft*1LL*nums.at(i));
            ans -= (smallRight*smallLeft*1LL*nums.at(i));

        }

        return ans;


    }



int main(){
   


    return 0;
}