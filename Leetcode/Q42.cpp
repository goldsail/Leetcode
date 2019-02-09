class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size();
        
        vector<int> left = vector<int>(N);
        int hleft = 0;
        for (int i = 0; i < N; i++) {
            hleft = max(hleft, height[i]);
            left[i] = hleft - height[i];
        }
        
        vector<int> right = vector<int>(N);
        int hright = 0;
        for (int i = N - 1; i >= 0; i--) {
            hright = max(hright, height[i]);
            right[i] = hright - height[i];
        }
        
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += min(left[i], right[i]);
        }
        return sum;
    }
    
private:
    static int min(int a, int b) {
        return a < b ? a : b;
    }
    
    static int max(int a, int b) {
        return a > b ? a : b;
    }
};