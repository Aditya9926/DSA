#include<iostream>
using namespace std;

bool searchmatrix(int matrix[][3], int row, int col, int tar){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(matrix[i][j] == tar){
                cout << "Element found at position: (" << i+1 << ", " << j+1 << ")" << endl;
                return true;
            }
        }
    }
    cout << "Element not found (-1,-1)" << endl;
    return false;
}

int main (){
    int mat[4][3] = {{1,2,3},{4,5,6},{10,11,12},{7,8,9}};
    int row = 4, col = 3, tar = 12;
    searchmatrix(mat, row, col, tar);
}