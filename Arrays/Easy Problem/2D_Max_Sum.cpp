#include<iostream>
using namespace std;

int maxsum(int mat[4][4], int row, int col){
    int maxsum = 0; 
    for(int i = 0; i < row; i++){
        int sum = 0;
        for(int j = 0; j < col; j++){
            sum += mat[i][j];
        }
        maxsum = max(maxsum, sum);
    }
    return maxsum;
}   

int main (){
    int mat[4][4] = {{10,50,80,20},{80,50,20,80},{60,50,60,60},{40,40,30,40}};
    int row = 4,col = 4;
    cout << maxsum(mat,row,col) << endl;
    return 0;
}