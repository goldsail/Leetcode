class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (nums.size() == 1 || sum % 2 != 0) {
            return false;
        }
        
        int N = nums.size();
        int K = sum / 2;
        
        vector<vector<bool>> table = vector<vector<bool>>(N + 1, vector<bool>(K + 1, false));
        
        table[0][0] = true;
        for (int i = 1; i <= N; i++) {
            table[i][0] = true;
        }
        for (int j = 1; j <= K; j++) {
            table[0][j] = false;
        }
        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= K; j++) {
                
                int p = j - nums[i - 1];
                
                table[i][j] = table[i - 1][j] || ((p >= 0) && table[i - 1][p]);
                
            }
        }
        return table[N][K];
    }
};