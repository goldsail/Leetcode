class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return findPeakElement(nums.data(), 0, nums.size(), nums.size());
    }
    
private:
    static int findPeakElement(const int *nums, int lo, int hi, int N) {
        if (hi - lo < 4) {
            for (int i = lo; i < hi; i++) {
                if ((i - 1 < 0) || (nums[i] > nums[i - 1])) {
                    if ((i + 1 >= N) || (nums[i] > nums[i + 1])) {
                        return i;
                    }
                }
            }
            return -1;
        }
        
        int mid = (lo + hi + 1) / 2;
        if (nums[mid - 1] < nums[mid]) {
            return findPeakElement(nums, mid - 1, hi, N);
        } else {
            return findPeakElement(nums, lo, mid + 1, N);
        }
    }
};