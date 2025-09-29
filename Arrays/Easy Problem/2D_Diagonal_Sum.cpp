#include <iostream>
using namespace std;

int maxsum(int mat[4][4], int row, int col)
{
    int sum = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j)
            {
                sum += mat[i][j];
            }
            else if (j == col - i - 1)
            {
                sum += mat[i][j];
            }
        }
    }
    return sum;
}

int maxsumopt(int mat[4][4], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += mat[i][i];

        if (i != n-i-1)
        {
            sum += mat[i][n-i-1];
        }
    }
    return sum;
}

int main()
{
    int mat[4][4] = {{10, 50, 80, 20},
                     {80, 50, 20, 80},
                     {60, 50, 60, 60},
                     {40, 40, 30, 40}};
    int row = 4, col = 4, n = 4;
    cout << maxsum(mat, row, col) << endl;
    cout <<maxsumopt(mat,n) << endl;
    return 0;
}