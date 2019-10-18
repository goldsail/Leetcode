class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int N = board.size();
        queue<pair<int, int>> openSet;
        unordered_set<int> closedSet;
        openSet.push(make_pair(1, 0));
        closedSet.insert(1);
        while (!openSet.empty()) {
            auto curr = openSet.front();
            openSet.pop();
            if (curr.first == N * N) {
                return curr.second;
            }
            vector<int> neighbors = getNeighbors(curr.first, board);
            for (int n : neighbors) {
                if (closedSet.find(n) == closedSet.end()) {
                    openSet.push(make_pair(n, curr.second + 1));
                    closedSet.insert(n);
                }
            }
        }
        return -1;
    }
    
private:
    static pair<int, int> getCoordinate(int s, int N) {
        assert(s > 0 && s <= N * N);
        int r = N - 1 - (s - 1) / N;
        int c = (N - 1 - r) % 2 == 0 ? (s - 1) % N : (N - 1 - (s - 1) % N);
        return make_pair(r, c);
    }
    
    static vector<int> getNeighbors(int s, const vector<vector<int>>& board) {
        int N = board.size();
        vector<int> result;
        for (int i = 1; i <= 6; i++) {
            int x = s + i;
            if (x <= N * N) {
                auto temp = getCoordinate(x, N);
                int t = board[temp.first][temp.second];
                if (t < 0) {
                    result.push_back(x);
                } else {
                    result.push_back(t);
                }
            }
        }
        return result;
    }
};
