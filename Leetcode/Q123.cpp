class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return maxProfit(prices, 2);
    }
    
private:
    int maxProfit(vector<int> &prices, int K) {
        if (prices.size() < 2 || K <= 0) return 0;
        
        // table[k][n] means maximum profit as of the n-th day with at most k transactions
        vector<vector<int>> table = vector<vector<int>>(K + 1, vector<int>(prices.size(), 0));
        
        for (int k = 1; k <= K; k++) {
            int cost = prices[0]; // current cost of holding stock
            for (int n = 1; n < prices.size(); n++) {
                table[k][n] = max(
                    table[k][n - 1], // if no transactions
                    prices[n] - cost // if selling the stock
                );
                cost = min(
                    cost, // if no transactions
                    prices[n] - table[k - 1][n] // if buying a stock with one transaction
                );
            }
        }
        return table[K][prices.size() - 1];
    }
};