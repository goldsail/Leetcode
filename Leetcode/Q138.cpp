/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        this->nodeMap = unordered_map<Node *, Node *>();
        if (head == nullptr) { return nullptr; }
        copyRandomList_(head);
        return nodeMap[head];
    }
    
    // Call this function when curr does not exist in the nodeMap
    void copyRandomList_(Node *curr) {
        
            
        nodeMap[curr] = new Node(curr->val, nullptr, nullptr);

        Node *next = curr->next;
        if (next != nullptr) {
            if (nodeMap.find(next) == nodeMap.end()) {
                copyRandomList_(next);
            }
            nodeMap[curr]->next = nodeMap[next];
        }


        Node *random = curr->random;
        if (random != nullptr) {
            if (nodeMap.find(random) == nodeMap.end()) {
                copyRandomList_(random);
            }
            nodeMap[curr]->random = nodeMap[random];
        }
            
        
    }
    
private:
    unordered_map<Node *, Node *> nodeMap;
};