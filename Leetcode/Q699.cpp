class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> result;
        int best = 0;
        map<int, int> heights; // heights[x] is height to the left of point x
        for (vector<int>& position : positions) {
            int u = position[0];
            int v = position[0] + position[1];
            int h = position[1];
            auto leftLower = heights.lower_bound(u);
            auto leftUpper = heights.upper_bound(u);
            auto rightLower = heights.lower_bound(v);
            auto rightUpper = heights.upper_bound(v);
            int height = 0;
            for (auto it = leftUpper; it != rightLower; ++it) {
                height = max(height, it->second);
            }
            if (rightLower != heights.end()) {
                height = max(height, rightLower->second);
            }
            //
            int leftHeight = (leftLower == heights.end()) ? 0 : leftLower->second;
            //
            heights.erase(leftLower, rightUpper);
            heights[u] = leftHeight;
            heights[v] = height + h;
            best = max(best, height + h);
            result.push_back(best);
        }
        return result;
    }
};
