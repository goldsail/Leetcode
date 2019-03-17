class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        this->results = vector<vector<int>>();
        this->stk = vector<int>();
        //
        sort(candidates.begin(), candidates.end());
        iterate(candidates, candidates.begin(), target);
        return results;
    }
    
private:
    vector<vector<int>> results;
    vector<int> stk; // a stack
    bool iterate(const vector<int> &candidates, const vector<int>::iterator &it, int target) {
        if (target < 0) {
            return false;
        }
        
        if (it == candidates.end()) {
            if (target == 0) {
                results.push_back(stk);
                return false;
            } else {
                // if target > 0
                return true;
            }
        }
        
        vector<int>::iterator next_it = it;
        while (next_it != candidates.end() && (*next_it) == (*it)) {
            ++next_it;
        }
        
        int i = 0;
        while ((i <= (next_it - it)) && iterate(candidates, next_it, target - i * (*it))) {
            i++;
            stk.push_back(*it);
        }
        
        while (i > 0) {
            i--;
            stk.pop_back();
        }
        return true;
    }
};