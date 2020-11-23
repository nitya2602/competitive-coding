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
    void inorder(TreeNode* root, int &sum, int low, int high)
    {
        if(root == NULL)
            return;
        if(root -> val > high)
            inorder(root -> left, sum, low, high);
        else if(root -> val >= low && root -> val <= high)
        {
            sum += root -> val;
            inorder(root -> left, sum, low, high);
            inorder(root -> right, sum, low, high);
        }
        else
            inorder(root -> right, sum, low, high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        inorder(root, sum, low, high);
        return sum;
    }
};