#include<iostream>
#include<vector>
using namespace std;

// Brute Force Method 
bool searchMatrix(vector<vector<int>>& matrix, int target){
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            if(matrix[i][j] == target){
                return true;
            }
        }
    }
    return false;
}

// Optimized Method
bool searchinrow(vector<vector<int>>& matrix, int target,int row){
    int n = matrix[0].size();
    int s = 0, e = n-1;
    while(s <= e){
        int mid = s + (e-s)/2;
        if(target == matrix[row][mid]){
            return true;
        }
        else if(target > matrix[row][mid]){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return false;
}

bool searchmatrix(vector<vector<int>>& matrix, int target){
    int m = matrix.size();
    int n = matrix[0].size();
    int s = 0, e = m-1;
    while(s <= e){
        int mid = s +(e-s)/2;
        if(target >= matrix[mid][0] && target <= matrix[mid][n-1]){
            return searchinrow(matrix,target,mid);
        }
        else if(target >=  matrix[mid][n-1]){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        } 
    }
    return false;
}

int main(){
    vector<vector<int>> mat = {{1,3,5,7,8},
                    {10,11,16,20,21},
                    {23,30,34,60,80}};
    int tar = 80;

    // for brute force method
    bool mt = searchMatrix(mat,tar);
    if(mt == 0){
        cout << "Element not found." << endl;
    }
    else{
        cout << "Element found." << endl;
    }

    // for optimised method 
    cout << searchmatrix(mat,tar) << endl;
    return 0;
}