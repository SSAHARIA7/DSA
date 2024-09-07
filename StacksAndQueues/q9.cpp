#include <iostream>
#include <vector>
#include <map>
#include <stack>

std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {

        std::map<int,int> ans;
        std::stack<int> st;
        std::vector<int> finalAns;
        for(int i{static_cast<int>(nums2.size()) - 1} ;i>=0; i--){

            if(st.empty()){
                st.push(nums2.at(i));
                ans.insert(std::make_pair(nums2.at(i),-1));
            }else{

                while(!st.empty()){
                    if(st.top() <= nums2.at(i)){
                        st.pop();
                    }else{
                        break;
                    }
                }
                if(st.empty()){
                    ans.insert(std::make_pair(nums2.at(i),-1));

                }else{
                    ans.insert(std::make_pair(nums2.at(i),st.top()));
;
                }

                st.push(nums2.at(i));
            }
        }
        for(int i{} ; i<nums1.size() ; i++){
            finalAns.push_back(ans.at(nums1.at(i)));
        }
        
        return finalAns;
    }