class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> nextGreaterIdx(T.size(), T.size());
        stack<int> monoStk;
        for (int i = 0; i < T.size(); i++) {
            while (!monoStk.empty() && T[monoStk.top()] < T[i]) {
                nextGreaterIdx[monoStk.top()] = i;
                monoStk.pop();
            }
            monoStk.push(i);
        }
        //
        vector<int> result(T.size());
        for (int i = 0; i < T.size(); i++) {
            if (nextGreaterIdx[i] != T.size()) {
                result[i] = nextGreaterIdx[i] - i;
            } else {
                result[i] = 0;
            }
        }
        return result;
    }
};

