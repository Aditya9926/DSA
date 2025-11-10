#include <iostream>
#include <vector>
using namespace std;

bool issafe(vector<string> &board, int row, int col, int n)
{
    // Horizontal
    for (int i = 0; i < n; i++)
    {
        if (board[row][i] == 'Q')
        {
            return false;
        }
    }

    // Vertical
    for (int j = 0; j < n; j++)
    {
        if (board[j][col] == 'Q')
        {
            return false;
        }
    }

    // Left Digonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    // Right Diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    return true;
}

void NQueen(vector<string> &board, int row, int n, vector<vector<string>> &ans)
{
    if (row == n)
    {
        ans.push_back({board});
        return;
    }
    for (int j = 0; j < n; j++)
    {
        if (issafe(board, row, j, n))
        {
            board[row][j] = 'Q';
            NQueen(board, row + 1, n, ans);
            board[row][j] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;
    NQueen(board, 0, n, ans);
    return ans;
}

int main()
{
    int n = 4;
    vector<vector<string>> res = solveNQueens(n);
    for (auto str : res)
    {
        cout << "[ ";
        for (auto strs : str)
        {
            cout << "'" << strs << "'";
        }
        cout << "]" << endl;
    }
}