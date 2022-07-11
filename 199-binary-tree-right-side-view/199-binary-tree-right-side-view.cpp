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
    void solve (int i,vector<int>&ans,TreeNode* root){
        if (root==NULL)return;
        if (i==ans.size())
            ans.push_back(root->val);
        solve (i+1,ans,root->right);
        solve (i+1,ans,root->left);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
      solve (0,ans,root);
        return ans;
    }
};