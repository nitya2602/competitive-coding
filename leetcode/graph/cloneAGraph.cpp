/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        
        unordered_map<int, Node*> map;
        unordered_map<int, bool> visited;
        queue<Node*> q_temp, q_node;
        Node* ans = new Node(node -> val);
        visited[node -> val] = true;
        map[node -> val] = ans;
        
        for(int i = 0; i < node -> neighbors.size(); i++)
        {
            Node* temp = new Node(node -> neighbors[i] -> val);
            ans -> neighbors.push_back(temp);
            map[temp -> val] = temp;
            q_temp.push(temp);
            q_node.push(node -> neighbors[i]);
        }
        
        while(!q_temp.empty())
        {
            Node* temp = q_temp.front();
            Node* ref = q_node.front();
            q_temp.pop();
            q_node.pop();
            if(visited[ref -> val] == false)
            {
                for(int i = 0; i < ref -> neighbors.size(); i++)
                {
                    Node* temp1;
                    if(map[ref -> neighbors[i] -> val] == NULL)
                    {
                        temp1 = new Node(ref -> neighbors[i] -> val);
                        map[temp1 -> val] = temp1;
                    }
                    else
                        temp1 = map[ref -> neighbors[i] -> val];
                    temp -> neighbors.push_back(temp1);
                    q_temp.push(temp1);
                    q_node.push(ref -> neighbors[i]);
                }
            }
            visited[temp -> val] = true;
        }
        return ans;
    }
};