class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> seen;
        vector<string> result;
        for (const string &name : names) {
            string curr = name;
            int val = seen[name];
            while (seen[curr] > 0) {
                curr = name + "(" + to_string(val) + ")";
                val++;
                seen[name] = val;
            }
            result.push_back(curr);
            seen[curr]++;
        }
        return result;
    }
};
