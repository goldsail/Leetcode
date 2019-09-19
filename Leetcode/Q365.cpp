class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        assert(x >= 0 && y >= 0);
        using Pair = pair<int, int>;
        auto check = [z](const Pair& p) -> bool {
            return p.first == z || p.second == z || p.first + p.second == z;
        };
        auto next = [x, y](const Pair& p) -> vector<Pair> {
            int diff1 = min(x - p.first, p.second);
            int diff2 = min(p.first, y - p.second);
            return vector<Pair> {
                {0, p.second},
                {x, p.second},
                {p.first, 0},
                {p.first, y},
                {p.first + diff1, p.second - diff1},
                {p.first - diff2, p.second + diff2}
            };
        };
        //
        auto hash = [](const Pair& p) -> size_t {
            return std::hash<int>{}(p.first) ^ std::hash<int>{}(p.second);
        };
        auto comp = [](const Pair& p1, const Pair& p2) -> bool {
            return p1.first == p2.first && p1.second == p2.second;
        };
        unordered_set<Pair, decltype(hash), decltype(comp)> closedSet(100, hash, comp);
        queue<Pair> openSet;
        //
        closedSet.insert(Pair(0, 0));
        openSet.push(Pair(0, 0));
        //
        while (!openSet.empty()) {
            Pair curr = openSet.front();
            openSet.pop();
            if (check(curr)) {
                return true;
            }
            //
            vector<Pair> children = next(curr);
            for (const Pair& child : children) {
                if (closedSet.find(child) == closedSet.end()) {
                    closedSet.insert(child);
                    openSet.push(child);
                }
            }
        }
        return false;
    }
};
