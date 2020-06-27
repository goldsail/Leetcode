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
        if (node == nullptr) return nullptr;
        unordered_map<Node*, Node*> visited;
        queue<Node*> openSet;
        openSet.push(node);
        visited[node] = new Node(node->val);
        while (!openSet.empty()) {
            Node *curr = openSet.front();
            openSet.pop();
            for (Node *child : curr->neighbors) {
                if (visited.find(child) == visited.end()) {
                    visited[child] = new Node(child->val);
                    openSet.push(child);
                }
                visited[curr]->neighbors.push_back(visited[child]);
            }
        }
        return visited[node];
    }
};
