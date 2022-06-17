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
    int dfs (TreeNode* root , int &cnt)
    {
        if (root==NULL)
            return 1;
        int GoRight=dfs(root->right,cnt);
        int GoLeft=dfs(root->left,cnt);
        if (GoRight==-1 || GoLeft==-1)
        {
            cnt++;
            return 0;
        }
         if (GoRight==0 || GoLeft==0)
            return 1;
        return -1;  
    }
    int minCameraCover(TreeNode* root) {
        int cnt=0;
        int ans=dfs(root,cnt);
        return (ans==-1 ? ++cnt:cnt);
    }
};