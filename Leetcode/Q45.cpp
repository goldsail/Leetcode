// simple recursive solution, not DP or BFS

class Solution {
public:
    int jump(vector<int>& nums) {
        this->jumps = vector<int>(nums.size(), INT_MAX);
        return jump_(nums, 0);
    }
    
private:
    vector<int> jumps;
    
    int jump_(const vector<int> &nums, int pos) {
        
        if (pos >= nums.size() - 1) {
            return 0;
        }
        
        if (jumps[pos] < INT_MAX) {
            return jumps[pos];
        }
        
        int result = INT_MAX;
        for (int step = 1; step <= nums[pos] && pos + step < nums.size(); step++) {
            result = min(result, jump_(nums, pos + step));
        }
        
        if (result == INT_MAX) {
            return INT_MAX;
        } else {
            jumps[pos] = result + 1;
            return result + 1;
        }
        
    }
    
    static int min(int a, int b) {
        return a < b ? a : b;
    }
};