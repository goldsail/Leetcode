class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) {
            return;
        }
        
        vector<int>::iterator it = nums.end();
        do {
            --it;
        } while (it != nums.begin() && it[0] <= it[-1]);
        
        if (it == nums.begin()) {
            sort(nums.begin(), nums.end());
            return;
        }
        
        int minVal = (*it);
        vector<int>::iterator next_it = it;
        for (auto iter = it; iter != nums.end(); ++iter) {
            if (iter[0] > it[-1] && iter[0] <= minVal) {
                minVal = iter[0];
                next_it = iter;
            }
        }
        
        int temp = next_it[0];
        next_it[0] = it[-1];
        it[-1] = temp;
        
        sort(it, nums.end());
        return;
        
    }
};