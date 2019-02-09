class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        
        if (rectangles.size() == 0) return 0;
        
        vector<int> lenX;
        vector<int> lenY;
        
        const long MOD = 1000000007;
        
        long area = 0;
        vector<vector<bool>> board = compress(rectangles, lenX, lenY);
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j]) {
                    area += (long(lenX[i]) * long(lenY[j]));
                }
            }
        }
        // cout << area << endl;
        return int(area % MOD);
    }
    
private:
    static vector<vector<bool>> compress(const vector<vector<int>> &recs, vector<int> &lenX, vector<int> &lenY) {
        map<int, int> mapX;
        map<int, int> mapY;
        
        for (vector<int> rec : recs) {
            mapX[rec[0]] = 0;
            mapY[rec[1]] = 0;
            mapX[rec[2]] = 0;
            mapY[rec[3]] = 0;
        }
        
        lenX = vector<int>();
        lenY = vector<int>();
        
        int i = 0;
        int currX = -1;
        int prevX = -1;
        for (auto iter = mapX.begin(); iter != mapX.end(); iter++) {
            iter->second = i;
            prevX = currX;
            currX = iter->first;
            if (i > 0) lenX.push_back(currX - prevX);
            i++;
        }
        int X = i - 1;
        
        int j = 0;
        int currY = -1;
        int prevY = -1;
        for (auto iter = mapY.begin(); iter != mapY.end(); iter++) {
            iter->second = j;
            prevY = currY;
            currY = iter->first;
            if (j > 0) lenY.push_back(currY - prevY);
            j++;
        }
        int Y = j - 1;
        
        vector<vector<bool>> ret = vector<vector<bool>>(X, vector<bool>(Y, false));
        
        
        for (int i = 0; i < recs.size(); i++) {
            int x1 = mapX[recs[i][0]];
            int y1 = mapY[recs[i][1]];
            int x2 = mapX[recs[i][2]];
            int y2 = mapY[recs[i][3]];
            
            for (int u = x1; u < x2; u++) {
                for (int v = y1; v < y2; v++) {
                    ret[u][v] = true;
                }
            }
        }
        
        return ret;
    }
};