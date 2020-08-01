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
    int dfs(TreeNode* root, int L, int R, int &ans)
    {
        if(root!=NULL)
        {
            if(root->val>=L && root->val<=R)
                ans+=root->val;
            if(L<root->val)
                dfs(root->left, L, R, ans);
            if(root->val<R)
                dfs(root->right, L, R, ans);
        }
        return ans;
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        int ans=0;
        dfs(root, L, R, ans);
        return ans;
    }
};
