class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        for (int i = 0; i < (N + 1) / 2; i++) {
            for (int j = 0; j < N / 2; j++) {
                pair<int, int> loc1 = pair<int, int>(i, j);
                pair<int, int> loc2 = rotate(loc1, N);
                pair<int, int> loc3 = rotate(loc2, N);
                pair<int, int> loc4 = rotate(loc3, N);
                rotate(
                    matrix[loc1.first][loc1.second], 
                    matrix[loc2.first][loc2.second], 
                    matrix[loc3.first][loc3.second], 
                    matrix[loc4.first][loc4.second]
                );
            }
        }
    }
    
private:
    void rotate(int &a, int &b, int &c, int &d) {
        int a1 = a;
        int b1 = b;
        int c1 = c;
        int d1 = d;
        a = d1;
        b = a1;
        c = b1;
        d = c1;
    }
    
    pair<int, int> rotate(pair<int, int> loc, int N) {
        int x = loc.first;
        int y = loc.second;
        if (N % 2 == 0) {
            int cx = N / 2 - 1;
            int cy = N / 2 - 1;
            return pair<int, int>(cx + (y - cy), cy - (x - cx) + 1);
        } else {
            int cx = N / 2;
            int cy = N / 2;
            return pair<int, int>(cx + (y - cy), cy - (x - cx));
        }
    }
};