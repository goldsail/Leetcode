class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        using Pair = pair<int, int>;
        auto cmp = [](const Pair &a, const Pair &b) {
            return a.first + a.second < b.first + b.second;
        };
        priority_queue<Pair, vector<Pair>, decltype(cmp)> heap(cmp);
        for (int num1 : nums1) {
            for (int num2 : nums2) {
                heap.push(make_pair(num1, num2));
                if (heap.size() > k) heap.pop();
            }
        }
        vector<vector<int>> result;
        while (!heap.empty()) {
            result.push_back(vector<int>{ heap.top().first, heap.top().second });
            heap.pop();
        }
        return result;
    }
};
