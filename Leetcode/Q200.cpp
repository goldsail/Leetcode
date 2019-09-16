class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        //
        int result = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                result += bfs(i, j, grid);
            }
        }
        return result;
    }
    
private:
    int bfs(int x, int y, vector<vector<char>>& grid) {
        if (grid[x][y] == '1') {
            vector<pair<int, int>> neighbors = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            queue<pair<int, int>> que;
            que.push(make_pair(x, y));
            while (!que.empty()) {
                auto curr = que.front();
                que.pop();
                if (grid[curr.first][curr.second] == '0') continue;
                grid[curr.first][curr.second] = '0';
                //
                for (auto neighbor : neighbors) {
                    int i = curr.first + neighbor.first;
                    int j = curr.second + neighbor.second;
                    if (i >= 0 && i < grid.size()) {
                        if (j >= 0 && j < grid[0].size()) {
                            if (grid[i][j] == '1') {
                                que.push(make_pair(i, j));
                            }
                        }
                    }
                }
            }
            return 1;
        }
        return 0;
    }
};

