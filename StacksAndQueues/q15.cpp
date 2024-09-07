#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// std::vector < int > nextSmallerElements(std::vector < int > & nums) {
//       int n = nums.size();
//       std::vector < int > nse(n);
//       std::stack < int > st;
//       for (int i =  n - 1; i >= 0; i--) {
//         while (!st.empty() && nums.at(st.top()) >= nums.at(i)) {
//           st.pop();
//         }

//         if(st.empty()){
//             nse.at(i) = n;
//             st.push(i);
//         }else{
//             nse.at(i) = st.top();
//             st.push(i);
//         }

//       }
//       return nse;
//     }

// std::vector <int> prevSmallerElements(std::vector<int> &nums){
//     std::stack<int> st;
//     std::vector<int> ans;
//     for(int i{} ; i<nums.size() ; i++){

//             while(!st.empty() && nums.at(st.top()) > nums.at(i)){
//                 st.pop();
//             }


//             if(st.empty()){
//                 ans.push_back(-1);
//             }else{
//                 ans.push_back(st.top());
//             }
//             st.push(i);
//         }
//        return ans;
//     }

int largestRectangleArea(vector < int > & heights) {
      int n = heights.size();
      stack < int > st;
      int leftsmall[n], rightsmall[n];
      for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
          st.pop();
        }
        if (st.empty())
          leftsmall[i] = 0;
        else
          leftsmall[i] = st.top() + 1;
        st.push(i);
      }
      // clear the stack to be re-used
      while (!st.empty())
        st.pop();

      for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i])
          st.pop();

        if (st.empty())
          rightsmall[i] = n - 1;
        else
          rightsmall[i] = st.top() - 1;

        st.push(i);
      }
      int maxA = 0;
      for (int i = 0; i < n; i++) {
        maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
      }
      return maxA;
    }