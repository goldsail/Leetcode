class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<char> result(k, '0');
        vector<char> arr1, arr2;
        for (int x : nums1) arr1.push_back('0' + x);
        for (int x : nums2) arr2.push_back('0' + x);
        //
        auto dp1 = maxNumber(arr1, k);
        auto dp2 = maxNumber(arr2, k);
        for (int i = 0; i <= k; i++) {
            if (i <= int(arr1.size()) && k - i <= int(arr2.size())) {
                auto nums = maxNumber(
                    dp1[arr1.size()][i], 
                    dp2[arr2.size()][k - i]);
                if (cmpNumber(result, nums)) {
                    result = nums;
                }
            }
        }
        //
        vector<int> ret;
        for (char x : result) ret.push_back(x - '0');
        return ret;
    }
    
private:
    vector<vector<vector<char>>> maxNumber(vector<char>& nums, int k) {
        k = min(k, int(nums.size()));
        auto dp = vector<vector<vector<char>>>(nums.size() + 1, 
                                               vector<vector<char>>(k + 1));
        for (int i = 0; i <= nums.size(); i++) 
            dp[i][0] = vector<char>();
        for (int i = 1; i <= k; i++) 
            dp[i][i] = vector<char>(nums.begin(), nums.begin() + i);
        for (int j = 1; j <= k; j++) {
            for (int i = j + 1; i <= nums.size(); i++) {
                vector<char> s1 = dp[i - 1][j];
                vector<char> s2 = dp[i - 1][j - 1];
                s2.push_back(nums[i - 1]);
                dp[i][j] = cmpNumber(s1, s2) ? s2 : s1;
            }
        }
        return dp;
    }
    
    vector<char> maxNumber(vector<char>& nums1, vector<char>& nums2) {
        vector<char> result;
        vector<char>::iterator it1 = nums1.begin();
        vector<char>::iterator it2 = nums2.begin();
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
    
    bool cmpNumber(const vector<char>& nums1, const vector<char>& nums2) {
        return lexicographical_compare(
            nums1.begin(), nums1.end(), 
            nums2.begin(), nums2.end());
    }
};
