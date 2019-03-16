class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        do {
            results.push_back(nums);
        } while (next_permutation(nums));
        return results;
    }
    
private:
    bool next_permutation(vector<int> &nums) {
        if (nums.size() < 2) return false;
        
        // find the first i in reverse order that satisfies nums[i - 1] < nums[i]
        int i = nums.size();
        do {
            i--;
        } while (i > 0 && nums[i] < nums[i - 1]);
        
        if (i == 0) {
            return false;
        }
        
        // find j in range i to end such that nums[j] is the smallest among all numbers greater than nums[i - 1]
        int j = i;
        for (int k = i; k < nums.size(); k++) {
            if (nums[k] > nums[i - 1] && nums[k] < nums[j]) {
                j = k;
            }
        }
        
        // swap (i - 1) and j
        swap(nums[i - 1], nums[j]);
        
        // reverse the range i to end
        reverse(nums.begin() + i, nums.end());
        return true;
    }
    
    static void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
};