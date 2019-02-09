class Solution {
public:
    int countTriplets(vector<int>& A) {
        
        unordered_map<int, int> M;
        for (int a : A) {
            for (int b : A) {
                int count = (M.find(a & b) == M.end()) ? 0 : M[a & b];
                M[a & b] = count + 1;
            }
        }
        int count = 0;
        
        for (auto iter = M.begin(); iter != M.end(); iter++) {
            for (int c : A) {
                if ((c & iter->first) == 0) {
                    count += (iter->second);
                }
            }
        }
        
        return count;
    }
};