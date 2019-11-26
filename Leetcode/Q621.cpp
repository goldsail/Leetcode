class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n < 1) return tasks.size();
        array<int, 26> count = {0};
        for (char c : tasks) count[c - 'A']++;
        using Pair = pair<char, int>;
        auto cmp = [](Pair a, Pair b) -> bool {
            return a.second < b.second 
                || (a.second == b.second && a.first < b.first);
        };
        priority_queue<Pair, vector<Pair>, decltype(cmp)> heap(cmp);
        for (int c = 'A'; c <= 'Z'; c++) {
            if (count[c - 'A'] > 0) {
                heap.push(make_pair(c, count[c - 'A']));
            }
        }
        string result;
        while (!heap.empty()) {
            vector<Pair> temp;
            for (int i = 0; i <= n; i++) {
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
        int p = result.size();
        while (p > 0 && result[p-1] == '0') p--;
        return p;
    }
};
