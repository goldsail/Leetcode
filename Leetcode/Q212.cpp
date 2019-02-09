class Solution {
    
    class Trie;
    
    using Point = pair<int, int>;
    
    struct Hasher {
        std::size_t operator () (const std::pair<int, int> &p) const {
            auto h1 = std::hash<int>{}(p.first);
            auto h2 = std::hash<int>{}(p.second);
            return h1 ^ h2;
        }
    };
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        if (board.empty() || board[0].empty() || words.empty()) {
            return vector<string>();
        }
        
        unordered_set<string> results;
        
        Trie trie(words);
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                trie.resetToRoot();
                
                stack<Point> pathStack;
                pathStack.push(Point(i, j));
                
                unordered_set<Point, Hasher> pathSet;
                pathSet.insert(Point(i, j));
                
                explore(pathStack, pathSet, board, trie, results);
            }
        }
        
        vector<string> ret;
        for (string s : results) {
            ret.push_back(s);
        }
        return ret;
    }
    
private:
    
    void explore(stack<Point> &pathStack, unordered_set<Point, Hasher> &pathSet, 
                 const vector<vector<char>>& board, Trie &trie, unordered_set<string> &results) {
        Point point = pathStack.top();
        int i = point.first;
        int j = point.second;
        
        if (trie.findAndVisitChild(board[i][j])) {
            string s = trie.currentWord();
            if (s.size() > 0 && results.find(s) == results.end()) {
                results.insert(s);
            }
            //
            vector<Point> offsets = { Point(-1, 0), Point(1, 0), Point(0, -1), Point(0, 1) };
            for (Point offset : offsets) {
                int u = i + offset.first;
                int v = j + offset.second;
                if (u >= 0 && u < board.size() && v >= 0 && v < board[0].size()) {
                    if (pathSet.find(Point(u, v)) == pathSet.end()) {
                        pathStack.push(Point(u, v));
                        pathSet.insert(Point(u, v));
                        explore(pathStack, pathSet, board, trie, results);
                        pathStack.pop();
                        pathSet.erase(Point(u, v));
                    }
                }
            }
            trie.resetToParent();
        }
        
        
        
    }
    
    
    class Trie {
        struct TrieNode {
            bool isEndOfWord = false;
            char letter = ':';
            array<TrieNode*, 26> children = { nullptr };
            TrieNode *parent = nullptr;
        };
        
    public:
        Trie(const vector<string>& words) {
            this->root = new TrieNode();
            this->current = root;
            
            for (string s : words) {
                TrieNode *curr = this->root;
                for (int i = 0; i < s.size(); i++) {
                    if (curr->children[s[i] - 'a'] == nullptr) {
                        TrieNode *temp = new TrieNode();
                        temp->letter = s[i];
                        temp->parent = curr;
                        curr->children[s[i] - 'a'] = temp;
                    }
                    curr = curr->children[s[i] - 'a'];
                    if (i == s.size() - 1) {
                        curr->isEndOfWord = true;
                    };
                }
            }
        }
        
        void resetToRoot() {
            this->current = this->root;
        }
        
        bool findAndVisitChild(char letter) {
            if (this->current->children[letter - 'a']) {
                this->current = this->current->children[letter - 'a'];
                return true;
            } else {
                return false;
            }
        }
        
        bool resetToParent() {
            if (this->current != this->root) {
                this->current = this->current->parent;
                return true;
            } else {
                return false;
            }
        }
        
        string currentWord() {
            if (this->current->isEndOfWord) {
                stack<char> stk;
                for (TrieNode *node = current; node != root; node = node->parent) {
                    stk.push(node->letter);
                }
                string s;
                while (!stk.empty()) {
                    s.push_back(stk.top());
                    stk.pop();
                }
                return s;
            } else {
                return "";
            }
        }
        
    private:
        TrieNode *root;
        TrieNode *current;
    };
};