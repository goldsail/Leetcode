class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> result(k, 0);
        // Try every possible partition from 0, 1, 2, ..., k-2, k-1, k.
        for (int i = 0; i <= k; i++) {
            if (i <= int(nums1.size()) && k - i <= int(nums2.size())) {
                auto sub1 = maxNumber(nums1, i);
                auto sub2 = maxNumber(nums2, k - i);
                auto nums = maxNumber(sub1, sub2);
                if (cmpNumber(result, nums)) {
                    result = nums;
                }
            }
        }
        return result;
    }
    
private:
    // Step 1: choose k digits from vector nums to form the largest number
    // Using monotonic stack with one thing additional: 
    // Stop popping elements when you've run out of k digits
    vector<int> maxNumber(vector<int>& nums, int k) {
        vector<int> stk;
        int count = nums.size() - k;
        for (int num : nums) {
            while (!stk.empty() && stk.back() < num && count > 0) {
                stk.pop_back();
                count--;
            }
            stk.push_back(num);
        }
        return vector<int>(stk.begin(), stk.begin() + k);
    }
    
    // Step 2: merge two vector into one largest number while keeping relative order
    // Similar to a merge sort.
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        vector<int>::iterator it1 = nums1.begin();
        vector<int>::iterator it2 = nums2.begin();
        while (it1 != nums1.end() || it2 != nums2.end()) {
            if (it1 == nums1.end()) {
                result.push_back(*it2);
                ++it2;
            } else if (it2 == nums2.end()) {
                result.push_back(*it1);
                ++it1;
            } else {
                if (lexicographical_compare(
                    it2, nums2.end(),
                    it1, nums1.end()
                )) {
                    result.push_back(*it1);
                    ++it1;
                } else {
                    result.push_back(*it2);
                    ++it2;
                }
            }
        }
        return result;
    }
    
    // Lexicographical compare
    bool cmpNumber(const vector<int>& nums1, const vector<int>& nums2) {
        return lexicographical_compare(
            nums1.begin(), nums1.end(), 
            nums2.begin(), nums2.end());
    }
};
