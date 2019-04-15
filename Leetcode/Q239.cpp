class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        if (nums.empty()) return vector<int>();
        
        if (!(k >= 0 && k <= int(nums.size()))) return vector<int>();
        
        vector<int> results;
        deque<int> mono;
        
        results.push_back(max_element(nums.begin(), nums.begin() + k).operator*());
        for (int i = 0; i < k; i++) {
            while (!mono.empty() && nums[mono.back()] < nums[i]) {
                mono.pop_back();
            }
            mono.push_back(i);
        }
        
        for (int i = k; i < nums.size(); i++) {
            
            if (!mono.empty() && mono.front() == i - k) {
                mono.pop_front();
            }
            
            while (!mono.empty() && nums[mono.back()] < nums[i]) {
                mono.pop_back();
            }
            mono.push_back(i);
            
            results.push_back(nums[mono.front()]);
            
        }
        
        return results;
        
    }
};