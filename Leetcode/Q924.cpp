class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        
        auto temp = getConnectedComponents(graph);
        vector<int> ccMap = temp.first; // the i-th node belongs to the ccMap[i]-th connected component
        vector<int> ccCount = temp.second; // the j-th component has ccCount[j] nodes
        
        vector<int> reduce = vector<int>(initial.size(), 0); // M[initial[i]] can be reduced by reduce[i]
        for (int i = 0; i < initial.size(); i++) {
            int idx = ccMap[initial[i]];
            int count = 0;
            for (int j = 0; j < initial.size(); j++) {
                if (ccMap[initial[j]] == idx) {
                    count++;
                }
            }
            if (count == 1) {
                reduce[i] = ccCount[idx];
            } else {
                reduce[i] = 0;
            }
        }
        
        int max = INT_MIN;
        int ret = initial.size();
        for (int i = 0; i < reduce.size(); i++) {
            if (reduce[i] > max || (reduce[i] == max && initial[i] < ret)) {
                max = reduce[i];
                ret = initial[i];
            }
        }
        return ret;
    }
    
private:
    
    pair<vector<int>, vector<int>> getConnectedComponents(const vector<vector<int>> &graph) {
        vector<int> ccMap = vector<int>(graph.size(), -1);
        vector<int> ccCount;
        
        int idx = 0;
        for (int i = 0; i < graph.size(); i++) {
            if (ccMap[i] < 0) {
                stack<int> stk;
                unordered_set<int> closedSet;
                stk.push(i);
                closedSet.insert(i);
                int cnt = 0;
                while (!stk.empty()) {
                    int x = stk.top();
                    stk.pop();
                    ccMap[x] = idx;
                    cnt++;
                    for (int j = 0; j < graph.size(); j++) {
                        if (graph[x][j]) {
                            if (closedSet.find(j) == closedSet.end()) {
                                stk.push(j);
                                closedSet.insert(j);
                            }
                        }
                    }
                }
                ccCount.push_back(cnt);
                idx++;
            }
        }
        
        return pair<vector<int>, vector<int>>(ccMap, ccCount);
    }
};