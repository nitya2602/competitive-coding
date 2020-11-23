/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    /*void preorder(Node* root, map<int, vector<Node*>>& map, int level)
    {
        if(root == NULL)
            return;
        map[level].push_back(root);
        preorder(root -> left, map, level + 1);
        preorder(root -> right, map, level + 1);
    }*/
    void preorder(Node* root)
    {
        if(root == NULL)
            return;
        if(root -> left)
            root -> left -> next = root -> right;
        if(root -> right)
            root -> right -> next = (root -> next) ? root -> next -> left : NULL;
        preorder(root -> left);
        preorder(root -> right);
    }
    Node* connect(Node* root) {
        /*map<int, vector<Node*>> map;
        preorder(root, map, 0);
        for(auto i = map.begin(); i != map.end(); i++)
        {
            for(int j = 0; j < i->second.size()-1; j++)
            {
                i -> second[j] -> next = i -> second[j+1];
            }
        }
        return root;*/
        preorder(root);
        return root;
    }
};