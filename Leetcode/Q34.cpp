class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return vector<int> {
            searchBegin(nums.data(), 0, nums.size(), target),
            searchEnd(nums.data(), 0, nums.size(), target)
        };
    }
    
private:
    static int searchBegin(const int *nums, int a, int b, int target) {
        if (b - a < 5) {
            for (int i = a; i < b; i++) {
                if (nums[i] == target) {
                    return i;
                }
            }
            return -1;
        }
        
        int mid = (a + b) / 2;
        if (nums[mid] > target) {
            return searchBegin(nums, a, mid, target);
        } else if (nums[mid] < target) {
            return searchBegin(nums, mid + 1, b, target);
        } else { // nums[mid] == target
            return searchBegin(nums, a, mid + 1, target);
        }
    }
    
    static int searchEnd(const int *nums, int a, int b, int target) {
        if (b - a < 5) {
            for (int i = b - 1; i >= a; i--) {
                if (nums[i] == target) {
                    return i;
                }
            }
            return -1;
        }
        
        int mid = (a + b) / 2;
        if (nums[mid] > target) {
            return searchEnd(nums, a, mid, target);
        } else if (nums[mid] < target) {
            return searchEnd(nums, mid + 1, b, target);
        } else { // nums[mid] == target
            return searchEnd(nums, mid, b, target);
        }
    }
};