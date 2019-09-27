class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];
        for_each(nums.begin(), nums.end(), [median](int& v) {
            v = abs(v - median);
        });
        return accumulate(nums.begin(), nums.end(), 0);
    }
};
