class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        auto cmp = [&count](int a, int b) -> bool {
            return count[a] > count[b];
        };
        priority_queue<int, vector<int>, decltype(cmp)> heap(cmp);
        //
        for (int num : nums) {
            ++count[num];
        }
        //
        for (auto it = count.begin(); it != count.end(); ++it) {
            heap.push(it->first);
            if (heap.size() > k) {
                heap.pop();
            }
        }
        //
        vector<int> result;
        while (!heap.empty()) {
            result.push_back(heap.top());
            heap.pop();
        }
        return result;
    }
};

