#include <iostream>
#include <vector>



void ratPathFinder(int mazeSize,int currentRow, int currentColumn , std::vector<std::vector<int>> &maze , std::vector<std::string> &ans, std::string &currentRoute){

    if(currentColumn == mazeSize-1 && currentRow == mazeSize-1){
        ans.push_back(currentRoute);
        return;
    }
    //down
    if(currentRow != mazeSize-1){
        if(maze.at(currentRow+1).at(currentColumn) != 0){
            currentRoute.push_back('D');
            maze.at(currentRow+1).at(currentColumn) = 0;
            ratPathFinder(mazeSize,currentRow+1,currentColumn,maze,ans,currentRoute);
            currentRoute.pop_back();
            maze.at(currentRow+1).at(currentColumn) = 1;
        }
    }
    //right
    if(currentColumn!=mazeSize-1){
        if(maze.at(currentRow).at(currentColumn+1) != 0){
            currentRoute.push_back('R');
            maze.at(currentRow).at(currentColumn+1) = 0;
            ratPathFinder(mazeSize,currentRow,currentColumn+1,maze,ans,currentRoute);
            currentRoute.pop_back();
             maze.at(currentRow).at(currentColumn+1) = 1;
        }
    }
    //left
    if(currentColumn!=0){
        if(maze.at(currentRow).at(currentColumn-1) != 0){
            currentRoute.push_back('L');
            maze.at(currentRow).at(currentColumn-1) = 0;
            ratPathFinder(mazeSize,currentRow,currentColumn-1,maze,ans,currentRoute);
            currentRoute.pop_back();
            maze.at(currentRow).at(currentColumn-1) = 1;
        }
    }
    //up
    if(currentRow != 0){
        if(maze.at(currentRow-1).at(currentColumn) != 0){
            currentRoute.push_back('U');
            maze.at(currentRow-1).at(currentColumn) = 0;
            ratPathFinder(mazeSize,currentRow-1,currentColumn,maze,ans,currentRoute);
            currentRoute.pop_back();
            maze.at(currentRow-1).at(currentColumn) = 1;
        }
    }

    return;

}



int main(){

    std::vector<std::string> ans;
    std::string currentRoute;
    
    











    std::vector<std::vector<int>> maze;
    int mazeSize{};
    std::cin>>mazeSize;
    for(int i{} ; i<mazeSize ; i++){
        std::vector<int> temp;
        for(int j{} ; j<mazeSize ; j++){
            int num;
            std::cin>>num;
            temp.push_back(num);
        }
        maze.push_back(temp);
    }
    if(maze.at(0).at(0) != 0 || maze.at(mazeSize-1).at(mazeSize-1) != 0){
        ratPathFinder(mazeSize,0,0,maze,ans,currentRoute);
    }

    for(auto s: ans){
        std::cout<<s<<std::endl;
    }

    return 0;
}