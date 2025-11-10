#include<iostream>
#include<vector>
using namespace std;

void getmaze(vector<vector<int>>& maze, int row, int col,string path,vector<string>& ans){
    int n = maze.size();
    if(row < 0 || col < 0 || row >= n || col >= n || maze[row][col] == 0 || maze[row][col] == -1){
        return;
    }

    if(row == n-1 && col == n-1){
        ans.push_back(path);
        return;
    }

    maze[row][col] = -1;
    // Down 
    getmaze(maze,row+1,col,path+"D",ans);

    // Up
    getmaze(maze,row-1,col,path+"U",ans);

    // Left
    getmaze(maze,row,col-1,path+"L",ans);

    //Right
    getmaze(maze,row,col+1,path+"R",ans);

    maze[row][col] = 1;
}

vector<string> findpath(vector<vector<int>>& mat){
    vector<string> ans;
    string path = "";
    int n = mat.size();
    getmaze(mat,0,0,path,ans);
    return ans;
} 

int main(){
    vector<vector<int>> arr = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<string> res = findpath(arr);
    for(auto path : res){
        cout << "[ ";
        for(auto pa : path){
            cout << pa << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}