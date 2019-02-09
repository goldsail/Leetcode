class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        
        int maxX;
        int maxY;
        compress(rectangles, maxX, maxY);
        
        vector<vector<bool>> board = vector<vector<bool>>(maxX, vector<bool>(maxY, false));
        
        for (vector<int> rec : rectangles) {
            for (int i = rec[0]; i < rec[2]; i++) {
                for (int j = rec[1]; j < rec[3]; j++) {
                    if (board[i][j]) {
                        return false;
                    }
                    board[i][j] = true;
                }
            }
        }
        
        for (int i = 0; i < maxX; i++) {
            for (int j = 0; j < maxY; j++) {
                if (!board[i][j]) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
private:
    static void compress(vector<vector<int>> &rectangles, int &maxX, int &maxY) {
        map<int, int> mapX;
        map<int, int> mapY;
        
        for (vector<int> rec : rectangles) {
            mapX[rec[0]] = 0;
            mapY[rec[1]] = 0;
            mapX[rec[2]] = 0;
            mapY[rec[3]] = 0;
        }
        
        int i = 0;
        for (auto iter = mapX.begin(); iter != mapX.end(); iter++) {
            iter->second = i;
            i++;
        }
        maxX = i - 1;
        
        int j = 0;
        for (auto iter = mapY.begin(); iter != mapY.end(); iter++) {
            iter->second = j;
            j++;
        }
        maxY = j - 1;
        
        for (int i = 0; i < rectangles.size(); i++) {
            rectangles[i][0] = mapX[rectangles[i][0]];
            rectangles[i][1] = mapY[rectangles[i][1]];
            rectangles[i][2] = mapX[rectangles[i][2]];
            rectangles[i][3] = mapY[rectangles[i][3]];
        }
        
    }
};