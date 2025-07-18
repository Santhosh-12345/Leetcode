/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool Valid(TreeNode* root,long long mini,long long maxi)
    {
        if(root==NULL)
        return true;
        if(mini>=root->val || root->val>=maxi)
        return false;
        return Valid(root->left,mini,root->val) && Valid(root->right,root->val,maxi);
    }
    bool isValidBST(TreeNode* root) {
        return Valid(root,LONG_MIN,LONG_MAX);
    }
};