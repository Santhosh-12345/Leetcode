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
    void inorder(TreeNode* root,int k,int& small,int& cnt)
    {
        if(root==NULL || cnt>=k)
        return;
        inorder(root->left,k,small,cnt);
        cnt++;
        if(cnt==k)
        {
            small=root->val;
            return;
        }
        
        inorder(root->right,k,small,cnt);
    }
    int kthSmallest(TreeNode* root, int k) {
        int small=INT_MAX;
        int cnt=0;
        inorder(root,k,small,cnt);
        return small;
    }
};