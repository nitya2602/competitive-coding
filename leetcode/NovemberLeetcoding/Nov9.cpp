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
    
    //we calculate difference for each node and save the max difference
    //for each node we have both max and min ancestor
    //finding max and min descendant for each node would require repeated traversals
    void preorder(TreeNode* root, int currMin, int currMax, int *difference)
    {
        if(root == NULL)
            return;
        int minDiff = abs(root->val - currMin);
        int maxDiff = abs(root->val - currMax);
        *difference = max(*difference, max(minDiff, maxDiff));
        preorder(root -> left, min(currMin, root -> val), max(currMax, root -> val), difference);
        preorder(root -> right, min(currMin, root -> val), max(currMax, root -> val), difference);
    }
    
    //for each root to leaf path, we maintain max an min value and take 
    //their difference on reaching the leaf node and propogate it back upwards
    int postorder(TreeNode* root, int currMin, int currMax)
    {
        if(root == NULL)
            return abs(currMin - currMax);
        int diffLeft = postorder(root -> left, min(root -> val, currMin), max(root -> val, currMax));
        int diffRight = postorder(root -> right, min(root -> val, currMin), max(root -> val, currMax));
        return max(diffLeft, diffRight);
    }
    int maxAncestorDiff(TreeNode* root) {
        int difference = 0;
        //preorder(root, root -> val, root -> val, &difference);
        difference = postorder(root, root -> val, root -> val);
        return difference;
    }
};