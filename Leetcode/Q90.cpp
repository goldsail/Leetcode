class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        this->stk = vector<int>();
        this->results = vector<vector<int>>();
        // sort the vector in ascending order
        sort(nums.begin(), nums.end());
        iterate(nums, nums.begin());
        return results;
    }
    
private:
    vector<int> stk; // a stack
    vector<vector<int>> results;
    void iterate(const vector<int> &nums, const vector<int>::iterator &it) {
        if (it == nums.end()) {
            // reach the end of the vector: return the current subset
            results.push_back(stk);
        } else {
            // find the next different number
            vector<int>::iterator next_it = it;
            while (next_it != nums.end() && (*next_it) == (*it)) {
                ++next_it;
            }
            // the current number (*it) can be repeated 0, 1, 2, ..., (next_it - it) times in the subset
            iterate(nums, next_it);
            for (int i = 0; i < next_it - it; i++) {
                stk.push_back(*it);
                iterate(nums, next_it);
            }
            for (int i = 0; i < next_it - it; i++) {
                stk.pop_back();
            }
        }
    }
};