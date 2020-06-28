class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        assert(k >= 0);
        if (k == 0) return;
        int n = nums.size();
        assert(n > 0);
        //
        int d = gcd(n, k); // stride
        int s = k % n; // increment step
        for (int i = 0; i < d; i++) {
            // starting from index i
            int count = 0;
            int curr = i;
            int t = nums[curr];
            for (int j = 0; j < (n / d); j++) {
                curr = (curr + s) % n;
                swap(nums[curr], t);
            }
        }
    }
    
private:
    int gcd(int a, int b) {
        if (a == b) return a;
        int m = max(a, b);
        int n = min(a, b);
        if (n == 0) return m;
        return gcd(m % n, n);
    }
    
    static void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
};
