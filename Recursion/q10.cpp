#include<iostream>
#include<vector>

bool findLangfordHelper(std::vector<int> &ans, int n) 
{

    if(n == 0) 
	{
        return true;
    }
    
    for(int i = 0; i < ans.size() - n - 1; i++)
	{
        
        // If empty slot
        if(ans[i] == 0 && ans[i + n + 1] == 0) 
		{
            
            // Fill slot
            ans[i] = n;
            ans[i + n + 1] = n;
            
            // Recursively call to fill remaining elements.
            if(findLangfordHelper(ans, n - 1)) 
			{
                return true;
            }
            
            // Undo
            ans[i] = 0;
            ans[i + n + 1] = 0;

        }
    } 

    return false;

}



int main(){
    int n;
    std::cin>>n;
    std::vector<int> ans(2*n);
   findLangfordHelper(ans,n);
    for(int i: ans){
        std::cout<<i<<" ";
    }
    return 0;
}