#include <iostream>
#include <vector>
#include <stack>


int trap(std::vector<int >& height) {
        std::stack<std::pair<int,int>> st;
        int base{};
        int ans{};
        for(int i{}; i<height.size() ; i++){

            if(st.empty()){
                if(height.at(i) > 0){
                    st.push(std::make_pair(height.at(i),1));
                    base = height.at(i);
                }
                continue;
            }

            if(height.at(i) < st.top().first){
                st.push(std::make_pair(height.at(i),1));
            }else if(height.at(i) == st.top().first){
                st.top().second++;
            }else{

                if(height.at(i) >= base){
                    while(st.top().first != base){
                        ans += (base-st.top().first) * st.top().second; 
                        st.pop();
                    }
                    st.pop();
                    st.push(std::make_pair(height.at(i),1));
                    base = height.at(i);
                }else{
                        int counter = 1;
                        while(st.top().first < height.at(i)){
                            ans += (height.at(i)-st.top().first) * st.top().second;
                            counter+=st.top().second;
                            st.pop();
                        }
                        if(st.top().first == height.at(i)){
                            st.top().second += counter;
                        }else{
                            st.push(std::make_pair(height.at(i),counter));
                        }
                    }
                }
            }
            return ans;
        }

    




int main(){
    std::vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};

    std::cout<<trap(v);

}
