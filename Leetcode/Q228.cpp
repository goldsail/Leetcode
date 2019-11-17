class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        auto buildString = [](int x, int y) -> string {
            if (x == y) return to_string(x);
            return to_string(x) + "->" + to_string(y);
        };
        vector<string> result;
        for (int curr = 0; curr < nums.size(); ) {
            int next = findNextStart(nums, curr);
            result.push_back(buildString(nums[curr], nums[next - 1]));
            curr = next;
        }
        return result;
    }
    
private:
    int findNextStart(const vector<int>& nums, int curr) {
        if (curr == nums.size() - 1) return nums.size();
        int min = curr + 1;
        int max = nums.size() - 1;
        while (true) {
            if (max - min < 5) {
                for (int p = min; p <= max; p++) {
                    if (long(nums[p]) - long(nums[curr]) != p - curr) {
                        return p;
                    }
                }
                return max + 1;
            }
            int mid = (min + max) / 2;
            if (long(nums[mid]) - long(nums[curr]) == mid - curr) {
                min = mid;
            } else {
                max = mid - 1;
            }
        }
        return -1;
    }
};
