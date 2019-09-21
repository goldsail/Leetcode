class Solution {
    struct Node {
        char letter = '0';
        bool isEnd = false;
        array<Node*, 26> next = {nullptr};
        
        static Node* buildTrie(const vector<string>& words) {
            Node* root = new Node();
            for (const string& word : words) {
                if (word.empty()) continue;
                Node* curr = root;
                for (char letter : word) {
                    assert(letter >= 'a' && letter <= 'z');
                    Node* child = curr->next[letter - 'a'];
                    if (child == nullptr) {
                        child = new Node();
                        child->letter = letter;
                        curr->next[letter - 'a'] = child;
                    }
                    curr = child;
                }
                curr->isEnd = true;
            }
            return root;
        }
        
        bool findWord(const string& word, int start, int end) {
            Node* curr = this;
            for (int i = start; i < end; i++) {
                if (curr->next[word[i] - 'a'] != nullptr) {
                    curr = curr->next[word[i] - 'a'];
                } else {
                    return false;
                }
            }
            return curr->isEnd;
        }
    };
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Node* root = Node::buildTrie(words);
        vector<string> result;
        for (const string& word : words) {
            if (checkWord(word, root)) {
                result.push_back(word);
            }
        }
        return result;
    }
    
private:
    bool checkWord(const string& word, Node* root) {
        if (word.empty()) return false;
        auto dp = vector<char>(word.size() + 1, 'F');
        dp[0] = 'T';
        for (int i = 1; i <= word.size(); i++) {
            for (int j = 0; j <= i; j++) {
                if (dp[j] == 'T') {
                    if (root->findWord(word, j, i)) {
                        if (!(j == 0 && i == word.size())) {
                            dp[i] = 'T';
                            break;
                        }
                    }
                }
            }
        }
        return dp.back() == 'T';
    }
};
