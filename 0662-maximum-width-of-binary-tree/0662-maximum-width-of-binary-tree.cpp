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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int ans=0;
        queue<pair<TreeNode*,int>>q; 
        q.push({root,0}); 
        while(!q.empty())
        {
            int first,last;
            int size=q.size();
            int mini=q.front().second; 
            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front().first; 
                long long currind = q.front().second - mini; 
                q.pop();
                if(i==0)
                    first=currind;
                if(i==size-1)
                    last=currind;
                if(current->left)
                    q.push({current->left,(long long)2*currind+1});
                if(current->right)
                    q.push({current->right,(long long)2*currind+2});
            }
            int res=last-first+1;
            ans=max(ans,res);
        }
        return ans;
    }
};