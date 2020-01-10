class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies = vector<int>(ratings.size(), 0);
        return solve(ratings.data(), candies.data(), 0, candies.size());
    }
    
private:
    int solve(const int *ratings, int *candies, int lo, int hi) {
        if (hi - lo == 0) return 0;
        if (hi - lo == 1) return (candies[lo] = 1);
        int mi = (lo + hi) / 2;
        int left = solve(ratings, candies, lo, mi);
        int right = solve(ratings, candies, mi, hi);
        
        for (int i = mi; i < hi; i++) {
            if (ratings[i - 1] < ratings[i] && candies[i - 1] >= candies[i]) {
                right += (candies[i - 1] + 1 - candies[i]);
                candies[i] = candies[i - 1] + 1;
            } else {
                break;
            }
        }
        
        for (int i = mi; i > 0; i--) {
            if (ratings[i - 1] > ratings[i] && candies[i - 1] <= candies[i]) {
                left += (candies[i] + 1 - candies[i - 1]);
                candies[i - 1] = candies[i] + 1;
            } else {
                break;
            }
        }
        
        return left + right;
    }
};
