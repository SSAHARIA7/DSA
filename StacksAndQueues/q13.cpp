#include <iostream>
#include <stack>
#include <vector>


std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        std::stack<int> st;
        std::vector<int> ans;

        for(int i{asteroids.size()-1} ; i>=0 ; i--){
            if(asteroids.at(i) < 0){
                st.push(asteroids.at(i));
            }else{
                if(!st.empty()){
                    if(-1*st.top() > asteroids.at(i)){
                        asteroids.at(i) = 0;
                    }else if(-1*st.top() < asteroids.at(i)){
                        while(!st.empty() && -1*st.top() < asteroids.at(i)){
                            st.pop();
                        }
                        if(!st.empty()){
                            if(asteroids.at(i) == -1*st.top()){
                                st.pop();
                            }
                            asteroids.at(i) = 0;
                        }

                    }else{
                        st.pop();
                        asteroids.at(i) = 0;    
                    }
                }
            }
        }

        for(int i: asteroids){
            if(i>0){
                ans.push_back(i);
            }else if(i<0){
                if(!st.empty() && i == st.top()){
                    ans.push_back(i);
                    st.pop();
                }
            }
        }

        return ans;
    }