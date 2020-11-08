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

/* We have two requirements:
    1) To maintain sum of sub trees to find tilt of the parent node
    2) To maintain sum of the tilts
   We return one thing from the function postorder and pass the other by reference.
   Sum would be different for left and right subtrees so return that and pass tilt by reference as 
   it is a common parameter for all the nodes. Whereas sum varies for different nodes and can't be generalised.
*/
class Solution {
public:
    int preorder(TreeNode* root, int* tilt)
    {
        if(root == NULL)
            return 0;
        
        int leftSum = preorder(root -> left, tilt);
        int rightSum = preorder(root -> right, tilt);
        *tilt = *tilt + abs(leftSum - rightSum);
        return leftSum + rightSum + root -> val;
    }
    
    int findTilt(TreeNode* root) {
        int tilt = 0;
        preorder(root, &tilt);
        return tilt;
    }
};