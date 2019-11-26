class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k <= 1) return s;
        array<int, 26> count = {0};
        for (char c : s) count[c - 'a']++;
        using Pair = pair<char, int>;
        auto cmp = [](Pair a, Pair b) -> bool {
            return a.second < b.second 
                || (a.second == b.second && a.first < b.first);
        };
        priority_queue<Pair, vector<Pair>, decltype(cmp)> heap(cmp);
        for (int c = 'a'; c <= 'z'; c++) {
            if (count[c - 'a'] > 0) {
                heap.push(make_pair(c, count[c - 'a']));
            }
        }
        string result;
        while (!heap.empty()) {
            vector<Pair> temp;
            for (int i = 0; i < k; i++) {
                if (heap.empty()) {
                    temp.push_back(make_pair('0', 0));
                } else {
                    Pair curr = heap.top();
                    heap.pop();
                    temp.push_back(curr);
                }
            }
            for (Pair p : temp) {
                result.push_back(p.first);
                if (p.second > 1) {
                    p.second--;
                    heap.push(p);
                }
            }
        }
        for (int i = s.size(); i < result.size(); i++) {
            if (result[i] != '0') return "";
        }
        return result.substr(0, s.size());
    }
};
