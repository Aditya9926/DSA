#include<iostream>
#include<vector>
using namespace std;

class Node{
    public :
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

// Building Pre-Order Tree using recursion :-
static int idx = -1;
Node* buildpretree(vector<int> preorder){
    idx ++;
    if(preorder[idx] == -1){
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildpretree(preorder);
    root->right = buildpretree(preorder);
    return root;
}

int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildpretree(preorder);
    cout << root->data << endl;
    cout << root->left->data << endl;
    cout << root->right->data << endl;
    return 0;
}