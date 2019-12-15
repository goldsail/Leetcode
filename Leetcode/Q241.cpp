class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> nums;
        vector<char> ops;
        for (int i = 0; i < input.size(); ) {
            if (input[i] >= '0' && input[i] <= '9') {
                int num = 0;
                while (i < input.size() && input[i] >= '0' && input[i] <= '9') {
                    num = 10 * num + input[i] - '0';
                    i++;
                }
                nums.push_back(num);
            } else {
                ops.push_back(input[i]);
                i++;
            }
        }
        assert(nums.size() == ops.size() + 1);
        int n = nums.size();
        //
        auto dp = vector(n, vector(n + 1, vector<int>()));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len;
                if (len == 1) {
                    dp[i][j].push_back(nums[i]);
                } else {
                    for (int k = i; k + 1 < j; k++) {
                        for (int left : dp[i][k + 1]) {
                            for (int right : dp[k + 1][j]) {
                                switch (ops[k]) {
                                    case '*':
                                        dp[i][j].push_back(left * right);
                                        break;
                                    case '+':
                                        dp[i][j].push_back(left + right);
                                        break;
                                    case '-':
                                        dp[i][j].push_back(left - right);
                                        break;
                                }
                            }
                        }
                    }
                }
            }
        }
        return vector<int>(dp[0][n].begin(), dp[0][n].end());
    }
};
