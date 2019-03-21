class Solution {
public:
    string getPermutation(int n, int k) {
        factorials = vector<int>(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            factorials[i] = i * factorials[i - 1];
        }
        
        vector<int> numbers;
        for (int i = 1; i <= n; i++) {
            numbers.push_back(i);
        }
        
        return getPermutation(k - 1, numbers);
    }
    
private:
    vector<int> factorials;
    string getPermutation(int k, vector<int> &numbers) {
        int n = numbers.size();
        if (n == 0) return "";
        
        int i = k / factorials[n - 1];
        int j = k % factorials[n - 1];
        
        int x = numbers[i];
        numbers.erase(numbers.begin() + i);
        
        string str;
        stringstream ss;
        ss << x;
        return ss.str() + getPermutation(j, numbers);
    }
};