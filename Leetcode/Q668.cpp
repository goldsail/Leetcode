class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = m * n;
        while (low < high) {
            int mid = (low + high) / 2;
            if (count(mid, m, n) < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
    
private: 
    
    static int count(int x, int m, int n) {
        // count how many elements in the table are smaller than or equal to x
        int ret = 0;
        for (int i = 1; i <= m; i++) {
            ret += min(n, x / i);
        }
        return ret;
    }
    
    static int min(int a, int b) {
        return a < b ? a : b;
    }
};