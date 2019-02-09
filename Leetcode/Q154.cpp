class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size() - 1);
    }
    
private:
    int findMin(const vector<int> &nums, int low, int high) {
        
        if (high - low < 4) {
            int min = INT_MAX;
            for (int i = low; i <= high; i++) {
                if (nums[i] < min) {
                    min = nums[i];
                }
            }
            return min;
        }
        
        if (nums[low] < nums[high]) {
            return nums[low]; // no rotation
        }
        
        int mid = (low + high) / 2;
        if (nums[low] < nums[mid] || nums[mid] > nums[high]) {
            return findMin(nums, mid, high);
        } else if (nums[low] > nums[mid] || nums[mid] < nums[high]) {
            return findMin(nums, low, mid);
        } else {
            return min(findMin(nums, low, mid), findMin(nums, mid, high));
        }
        
    }
    
    static int min(int a, int b) {
        return a < b ? a : b;
    }
};