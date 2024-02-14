#include <iostream>
#include <vector>

using namespace std;

typedef struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
};

vector<int> ans;
    
vector<int> inorderTraversal(TreeNode* root) {
    
    if(!root){ //no root
        return ans;
    }
    
    if(root->left){ //left child exists
        inorderTraversal(root->left);
    }
    ans.push_back(root->val);
    if(root->right){ //right child exists
        inorderTraversal(root->right);
    }

    return ans;
}