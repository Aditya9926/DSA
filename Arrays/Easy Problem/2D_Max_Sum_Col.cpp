#include<iostream>
using namespace std;

int maxsumcol(int mat[4][4], int row, int col){
    int maxsum = 0;
    for(int i = 0; i < col; i++){
        int sum = 0;
        for(int j = 0; j < row; j++){
            sum += mat[j][i];
        }
        maxsum = max(sum, maxsum);
    }
    return maxsum;
}

int main (){
    int mat[4][4] = {{10,50,80,20},{80,50,20,80},{60,50,60,60},{40,40,30,40}};
    int row = 4,col = 4;
    cout << maxsumcol(mat,row,col) << endl;
    return 0;
}