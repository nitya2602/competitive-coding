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
    int maxDepth(TreeNode* root) {
        int countL=0, countR=0;
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return 1;
        countL = maxDepth(root->left);
        countR = maxDepth(root->right);
        if(countR>countL)
            return countR+1;
        else
            return countL+1;
    }
};
