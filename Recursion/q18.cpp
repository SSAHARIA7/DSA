#include <iostream>
#include <vector>

    bool coloringPossible(int color, int vertex , std::vector<int> &vertexStatus,bool graph[101][101]){
    for(int i{1} ; i<vertex ; i++){
        if(graph[i-1][vertex-1] == 1){
            if(vertexStatus.at(i) == color){
                return false;
            }
        }
    }
    return true;
}

bool graphColoringHelper(int currentVertex, int noOfVertices, int noOfColors,bool graph[101][101], std::vector<int> &vertexStatus) {
    
    if(currentVertex > noOfVertices){
        return true;
    }
    
    for(int j{1} ; j<=noOfColors ; j++){
        if(coloringPossible(j,currentVertex,vertexStatus,graph)){
            vertexStatus.at(currentVertex) = j;
            if(graphColoringHelper(currentVertex+1,noOfVertices,noOfColors,graph,vertexStatus)){
                return true;
            }else{
                vertexStatus.at(currentVertex) = 0;
            } 
        }
    }

    return false;
    

}




int main(){
    bool graph[101][101];
    int m,n;
    

    
    return 0;
}