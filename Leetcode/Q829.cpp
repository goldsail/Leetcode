class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int ans = 0;
        for (int x = 1; x * x <= 2 * N; x++) {
            if ((2 * N) % x == 0) {
                int m = 2 * N / x - x + 1;
                if (m > 0 && m % 2 == 0) ans++;
            }
        }
        return ans;
    }
};
