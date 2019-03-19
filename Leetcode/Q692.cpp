class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        typedef unordered_map<string, int> Map;
        
        Map word_map;
        for (const string &word : words) {
            ++word_map[word];
        }
    
        auto cmp = [](const Map::iterator &left, const Map::iterator &right) {
            return (left->second > right->second)
                || (left->second == right->second && (left->first < right->first));
        };
        priority_queue<Map::iterator, vector<Map::iterator>, decltype(cmp)> heap(cmp);
        
        for (auto it = word_map.begin(); it != word_map.end(); ++it) {
            heap.push(it);
            if (heap.size() > k) {
                heap.pop();
            }
        }
        
        vector<string> results;
        while (!heap.empty()) {
            auto it = heap.top();
            heap.pop();
            results.push_back(it->first);
        }
        reverse(results.begin(), results.end());
        return results;
        
    }
};