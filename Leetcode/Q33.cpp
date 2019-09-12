class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size() - 1, target);
    }
    
private:
    int search(const vector<int>& nums, int lo, int hi, int target) {
        if (hi - lo < 6) {
            for (int i = lo; i <= hi; i++) {
                if (nums[i] == target) {
                    return i;
                }
            }
            return -1;
        }
        //
        int mid = (lo + hi) / 2;
        if (nums[lo] < nums[mid]) {
            if (nums[lo] <= target && target <= nums[mid]) {
                return search(nums, lo, mid, target);
            } else {
                return search(nums, mid, hi, target);
            }
        }
        if (nums[mid] < nums[hi]) {
            if (nums[mid] <= target && target <= nums[hi]) {
                return search(nums, mid, hi, target);
            } else {
                return search(nums, lo, mid, target);
            }
        }
        return -1;
    }
};

