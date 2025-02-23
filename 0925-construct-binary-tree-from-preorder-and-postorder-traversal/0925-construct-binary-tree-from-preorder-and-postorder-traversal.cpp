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
    int preind=0,postind=0;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* curr=new TreeNode(preorder[preind]);
        preind++;
        if(curr->val!=postorder[postind])
        curr->left=constructFromPrePost(preorder,postorder);
        if(curr->val!=postorder[postind])
        curr->right=constructFromPrePost(preorder,postorder);
        postind++;
        return curr;

    }
};