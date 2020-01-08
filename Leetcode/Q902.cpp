class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        string digits = to_string(N);
        int k = digits.size();
        vector<int> dp = vector<int>(k + 1, 0);
        // dp[i]:
        // number of valid answers
        // with exact i digits
        // for the last i digits of N
        dp[0] = 1;
        for (int i = 1; i <= k; i++) {
            for (string d : D) {
                if (d[0] < digits[k - i]) {
                    dp[i] += pow(D.size(), i - 1);
                } else if (d[0] == digits[k - i]) {
                    dp[i] += dp[i - 1];
                }
            }
        }
        int result = dp[k]; // answers with exact k digits
        for (int i = 1; i < k; i++) {
            result += pow(D.size(), i); // answers with less than k digits
        }
        return result;
    }
    
private:
    static int pow(int a, int n) {
        int result = 1;
        for (int i = 0; i < n; i++) {
            result *= a;
        }
        return result;
    }
};
