class Solution {
public:
    string alienOrder(vector<string>& words) {
        if (words.empty()) return "";
        if (words.size() == 1) return words[0];
        //
        unordered_map<char, int> degree;
        for (const string& word : words) {
            for (char c : word) {
                degree[c] = 0;
            }
        }
        //
        unordered_map<char, unordered_set<char>> list;
        for (auto it = words.begin() + 1; it != words.end(); ++it) {
            const string& prev = it[-1];
            const string& curr = it[0];
            for (int i = 0; i < min(prev.size(), curr.size()); i++) {
                if (prev[i] != curr[i]) {
                    list[prev[i]].insert(curr[i]);
                    break;
                }
            }
        }
        //
        
        for (auto it = list.begin(); it != list.end(); ++it) {
            for (char c : it->second) {
                ++degree[c];
            }
        }
        
        //
        string result;
        queue<char> que;
        for (auto it = degree.begin(); it != degree.end(); ++it) {
            if (it->second == 0) {
                que.push(it->first);
            }
        }
        while (!que.empty()) {
            char curr = que.front();
            que.pop();
            result.push_back(curr);
            for (char next : list[curr]) {
                --degree[next];
                if (degree[next] == 0) {
                    que.push(next);
                }
            }
        }
        if (result.size() != degree.size()) return "";
        return result;
    }
};
