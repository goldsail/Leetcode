class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> result(k, 0);
        for (int i = 0; i <= k; i++) {
            if (i <= int(nums1.size()) && k - i <= int(nums2.size())) {
                auto num1 = maxNumber(nums1, i);
                auto num2 = maxNumber(nums2, k - i);
                auto num = maxNumber(num1, num2);
                if (cmpNumber(result, num)) {
                    result = num;
                }
            }
        }
        return result;
    }
    
private:
    vector<int> maxNumber(vector<int>& nums, int k) {
        assert(k >= 0 && k <= nums.size());
        auto dp = vector<vector<vector<int>>>(
            nums.size() + 1, 
            vector<vector<int>>(k + 1));
        for (int i = 0; i <= nums.size(); i++) 
            dp[i][0] = vector<int>();
        for (int i = 1; i <= k; i++) 
            dp[i][i] = vector<int>(nums.begin(), nums.begin() + i);
        for (int j = 1; j <= k; j++) {
            for (int i = j + 1; i <= nums.size(); i++) {
                vector<int> s1 = dp[i - 1][j];
                vector<int> s2 = dp[i - 1][j - 1];
                s2.push_back(nums[i - 1]);
                dp[i][j] = cmpNumber(s1, s2) ? s2 : s1;
            }
        }
        return dp[nums.size()][k];
    }
    
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
    
    bool cmpNumber(const vector<int>& nums1, const vector<int>& nums2) {
        return lexicographical_compare(
            nums1.begin(), nums1.end(), 
            nums2.begin(), nums2.end());
    }
};

