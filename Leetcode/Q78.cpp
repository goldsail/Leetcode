class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        this->stk = vector<int>();
        this->results = vector<vector<int>>();
        iterate(nums, nums.begin());
        return results;
    }
    
private:
    vector<int> stk; // a stack
    vector<vector<int>> results;
    void iterate(const vector<int> &nums, const vector<int>::iterator &it) {
        if (it == nums.end()) {
            results.push_back(stk);
        } else {
            iterate(nums, it + 1);
            stk.push_back(*it);
            iterate(nums, it + 1);
            stk.pop_back();
        }
    }
};