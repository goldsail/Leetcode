class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        qsort(nums, 0, nums.size());
    }
    
private:
    int vi(vector<int>& nums, int x) {
        assert(x >= 0 && x < nums.size());
        // return x;
        int mid = nums.size() / 2;
        int res;
        if (x < mid) {
            res = x * 2 + 1;
        } else {
            res = 2 * (x - mid);
        }
        assert(res >= 0 && res < nums.size());
        return res;
    }
    
    void qsort(vector<int>& nums, int lo, int hi) {
        if (hi - lo <= 1) return;
        assert(lo >= 0 && hi <= nums.size());
        swap(nums, lo, lo + rand() % (hi - lo));
        int i = lo;
        int j = hi;
        int pivot = nums[vi(nums, lo)];
        while (true) {
            while (nums[vi(nums, ++i)] > pivot) {
                if (i == hi - 1) break;
            }
            while (nums[vi(nums, --j)] < pivot) {
                if (j == lo) break;
            }
            if (i >= j) break;
            swap(nums, i, j);
        }
        swap(nums, lo, j);
        qsort(nums, lo, j);
        qsort(nums, j + 1, hi);
    }
    
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[vi(nums, i)];
        nums[vi(nums, i)] = nums[vi(nums, j)];
        nums[vi(nums, j)] = temp;
    }
};
