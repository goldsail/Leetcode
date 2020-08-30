class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        table = vector(n + 1, vector<int>(n + 1, 0));
        //
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                table[i][j+1] = table[i][j] ^ arr[j];
            }
        }
        //
        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j; k < n; k++) {
                    if (table[i][j] == table[j][k+1]) {
                        result++;
                    }
                }
            }
        }
        return result;
    }
    
private:
    vector<vector<int>> table;
};
