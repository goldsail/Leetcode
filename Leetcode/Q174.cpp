class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        visited = vector<char>(dungeon.size() * dungeon[0].size(), 'F');
        return calculateMinimumHP(dungeon, 0, 0);
    }
    
private:
    vector<char> visited;
    int calculateMinimumHP(vector<vector<int>>& dungeon, int i, int j) {
        int index = i * dungeon[0].size() + j;
        if (visited[index] == 'F') {
            if (i == dungeon.size() - 1) {
                if (j == dungeon[0].size() - 1) {
                    dungeon[i][j] = max(1, 1 - dungeon[i][j]);
                } else {
                    dungeon[i][j] = max(1, calculateMinimumHP(dungeon, i, j + 1) - dungeon[i][j]);
                }
            } else {
                if (j == dungeon[0].size() - 1) {
                    dungeon[i][j] = max(1, calculateMinimumHP(dungeon, i + 1, j) - dungeon[i][j]);
                } else {
                    dungeon[i][j] = max(1, min(calculateMinimumHP(dungeon, i + 1, j) - dungeon[i][j], 
                                              calculateMinimumHP(dungeon, i, j + 1) - dungeon[i][j]));
                }
            }
            visited[index] = 'T';
        }
        return dungeon[i][j];
    }
};