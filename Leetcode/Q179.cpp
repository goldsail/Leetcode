class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // key fact: 
        // lexicographical_compare("ab", "ba")
        // is equivalent to
        // lexicographical_compare("a[c]b", "b[c]a")
        //
        sort(nums.begin(), nums.end(), [](int a, int b) -> bool {
            string x = to_string(b) + to_string(a);
            string y = to_string(a) + to_string(b);
            return lexicographical_compare(
                x.begin(), x.end(), 
                y.begin(), y.end());
        });
        if (nums.empty() || nums[0] == 0) return "0"; // in case all inputs are zero
        //
        string result;
        for (int x : nums) {
            result += to_string(x);
        }
        return result;
    }
};

