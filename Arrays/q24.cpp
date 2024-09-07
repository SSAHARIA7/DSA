#include <iostream>
#include <vector>

void rotateOuterBoundary(std::vector<std::vector<int>> &arr ,int n , int m, int boundary){


    for(int j{boundary}; j < m-1-boundary ; j++){
        int temp = arr.at(boundary).at(j);
        arr.at(boundary).at(j) = arr.at(n-1-j).at(boundary);
        arr.at(n-1-j).at(boundary) = arr.at(n-1-boundary).at(m-1-j);
        arr.at(n-1-boundary).at(m-1-j) = arr.at(j).at(m-1-boundary);
        arr.at(j).at(m-1-boundary) = temp;
    }
}



int main(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<int>>matrix;
    for(int i{} ; i<n ; i++){
        std::vector <int> temp;
        for(int j{} ; j<m ; j++){
            int tempNo;
            std::cin>>tempNo;
            temp.push_back(tempNo);
        }
        matrix.push_back(temp);
    }
    for(int boundary{} ; boundary<=n/2 ; boundary++){
        rotateOuterBoundary(matrix,n,m,boundary);
    }

    
    for(int i{} ; i<n ; i++){
        for(int j{} ; j<m ; j++){
            std::cout<<matrix.at(i).at(j)<<" "; 
        }
        std::cout<<std::endl;
    }


    //OR BEST SOLUTION === CONVERT THE MATRIX TO ITS TRANSPOSE AND THEN REVERSE EACH OF THE VECTOR ELEMENTS INSIDE IT.

}