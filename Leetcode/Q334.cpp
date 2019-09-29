class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // minimum number so far
        int first = numeric_limits<int>::max();
        // minimum number so far with a smaller preceding number
        int second = numeric_limits<int>::max();
        
        for (int num : nums) {
            if (num <= first) {
                // case 1: update first
                first = num;
            }
            if (num > first && num <= second) {
                // case 2: update second
                second = num;
            }
            if (num > second) {
                // case 3: exists an increasing triplet
                return true;
            }
        }
        return false;
    }
};
