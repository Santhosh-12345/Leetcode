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
class FindElements {
public:
    unordered_set<int>st;
    void func(TreeNode* curr,int val)
    {
        if(curr==NULL)
        return;
        st.insert(val);
        func(curr->left,2*val+1);
        func(curr->right,2*val+2);
    }
    FindElements(TreeNode* root) {
        st.insert(0);
        func(root->left,1);
        func(root->right,2);
    }
    
    bool find(int target) {
        return st.count(target)>0;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */