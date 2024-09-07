#include <iostream>
#include <vector>
#include <map>
#include <stack>


 std::vector<int> nextGreaterElements(std::vector<int>& nums2) {
        std::stack<int> st;
        std::vector<int> finalAns(nums2.size());
        for(int i{2*static_cast<int>(nums2.size()) - 1} ;i>=0; i--){

            if(st.empty()){
                st.push(nums2.at(i%nums2.size()));
                if(i<nums2.size()){
                    finalAns.at(i) = -1;

                }
            }else {

                while(!st.empty()){
                    if(st.top() <= nums2.at(i%nums2.size())){
                        st.pop();
                    }else{
                        break;
                    }
                }
                if(st.empty() && i<nums2.size()){
                    finalAns.at(i) = -1;

                }else if(i<nums2.size()){
                    finalAns.at(i) = st.top();
;
                }

                st.push(nums2.at(i%nums2.size()));
            }
        }
        
        return finalAns;
    }