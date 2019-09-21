class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        unordered_set<int> setA(A.begin(), A.end());
        unordered_set<int> setB(B.begin(), B.end());
        int sumA = accumulate(A.begin(), A.end(), 0);
        int sumB = accumulate(B.begin(), B.end(), 0);
        //
        for (int a : setA) {
            int b = a + (sumB - sumA) / 2;
            if (setB.find(b) != setB.end()) {
                return vector<int>{a, b};
            }
        }
        //
        return vector<int>{0, 0};
    }
};
