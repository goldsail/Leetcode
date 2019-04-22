class Solution {
public:
    string decodeString(string s) {
        
        
        Node root;
        root.num = 1;
        root.parent = nullptr;
        
        Node *curr = &root;
        
        for (int i = 0; i < s.size(); ) {
            
            if (s[i] >= '0' && s[i] <= '9') {
                Node *node = new Node();
                node->parent = curr;
                node->num = 0;
                while (s[i] >= '0' && s[i] <= '9') {
                    node->num = 10 * node->num + s[i] - '0';
                    i++;
                }
                curr->children.push_back(node);
                curr = node;
                continue;
            }
            
            if (s[i] == '[') {
                i++;
                continue;
            }
            
            if (s[i] == ']') {
                curr = curr->parent;
                i++;
                continue;
            }
            
            Node *node = new Node();
            node->num = -1;
            node->parent = curr;
            node->begin = i;
            while (i < s.size() && !(s[i] == ']' || (s[i] >= '0' && s[i] <= '9'))) {
                i++;
            }
            node->end = i;
            curr->children.push_back(node);
            continue;
        }
        
        //
        
        
        stringstream ss;
        
        root.print(s, ss);
        return ss.str();
        
    }
    
private:
    struct Node {
        int num;
        int begin;
        int end;
        vector<Node*> children;
        Node *parent;
        //
        void print(const string &s, stringstream &ss) {
            if (num < 0) {
                // string node
                ss << s.substr(begin, end - begin);
            } else {
                // number node
                stringstream temp;
                for (Node *child : children) {
                    child->print(s, temp);
                }
                string str = temp.str();
                for (int i = 0; i < num; i++) {
                    ss << str;
                }
            }
        }
    };
};