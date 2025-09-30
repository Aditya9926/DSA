#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
   int m = matrix.size(), n = matrix[0].size();
   int s = 0, e = n - 1;
   while (s < m && e >= 0)
   {
      if (target == matrix[s][e])
      {
         return true;
      }
      else if (target < matrix[s][e])
      {
         e--;
      }
      else
      {
         s++;
      }
   }
   return false;
}

int main()
{
   vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
   int target = 5;
   cout << searchMatrix(matrix, target) << endl;
}