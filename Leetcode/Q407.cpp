class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        using Grid = tuple<int, int, int>;
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        if (heightMap.size() < 3 || heightMap[0].size() < 3) return 0;
        //
        auto cmp = [](Grid a, Grid b) {
            return get<2>(a) > get<2>(b);
        };
        priority_queue<Grid, vector<Grid>, decltype(cmp)> que(cmp);
        auto visited = vector<vector<bool>>(
            heightMap.size(), vector<bool>(heightMap[0].size(), false));
        for (int i = 0; i < heightMap.size(); i++) {
            int last = heightMap[0].size() - 1;
            visited[i][0] = true;
            visited[i][last] = true;
            que.push(make_tuple(i, 0, heightMap[i][0]));
            que.push(make_tuple(i, last, heightMap[i][last]));
        }
        for (int j = 1; j < heightMap[0].size() - 1; j++) {
            int last = heightMap.size() - 1;
            visited[0][j] = true;
            visited[last][j] = true;
            que.push(make_tuple(0, j, heightMap[0][j]));
            que.push(make_tuple(last, j, heightMap[last][j]));
        }
        //
        int result = 0;
        while (!que.empty()) {
            auto curr = que.top();
            que.pop();
            vector<pair<int, int>> diffs = {
                {0, -1},
                {0, 1},
                {-1, 0},
                {1, 0}
            };
            for (pair<int, int> diff : diffs) {
                int x = get<0>(curr) + diff.first;
                int y = get<1>(curr) + diff.second;
                if (x >= 0 && x < heightMap.size()) {
                    if (y >= 0 && y < heightMap[0].size()) {
                        if (!visited[x][y]) {
                            visited[x][y] = true;
                            result += max(0, get<2>(curr) - heightMap[x][y]);
                            auto neighbor = make_tuple(
                                x, y, max(heightMap[x][y], get<2>(curr)));
                            que.push(neighbor);
                        }
                    }
                }
            }
        }
        return result;
    }
};
