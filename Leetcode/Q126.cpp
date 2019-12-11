class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        set<string> list(wordList.begin(), wordList.end());
        unordered_map<string, vector<string>> nextMap;
        nextMap[beginWord] = getNext(beginWord, list);
        for (string word : wordList) nextMap[word] = getNext(word, list);
        //
		queue<string> que;
        unordered_map<string, set<string>> preds;
        unordered_map<string, int> dists;
        for (string word : wordList) dists[word] = numeric_limits<int>::max();
        dists[beginWord] = 0;
		set<string> rec;
		//
		que.push(beginWord);
		rec.insert(beginWord);
        preds[beginWord] = set<string>();
        int targetDepth = numeric_limits<int>::max();
        //
		for (int i = 1; !que.empty() && i <= targetDepth; i++) { // at depth i
            set<string> currDepthRec;
            int prevQueSize = que.size();
            for (int j = 0; j < prevQueSize; j++) {
                string curr = que.front();
                que.pop();
                if (curr == endWord) targetDepth = i;
                for (const string next : nextMap[curr]) {
                    if (rec.find(next) == rec.end()) {
                        if (dists[next] > dists[curr] + 1) {
                            dists[next] = dists[curr] + 1;
                            que.push(next);
                        }
                        preds[next].insert(curr);
                        currDepthRec.insert(next);
                    }
                }
            }
            for (const string& temp : currDepthRec) rec.insert(temp);
        }
        //
        vector<vector<string>> result;
        vector<string> stk;
        traverse(beginWord, endWord, stk, result, preds);
        return result;
    }
    
private:
    void traverse(const string &target, const string &curr, vector<string>& stk, 
                  vector<vector<string>> &result, 
                  unordered_map<string, set<string>> &preds) {
        stk.push_back(curr);
        if (curr == target) {
            auto temp = stk;
            reverse(temp.begin(), temp.end());
            result.push_back(temp);
        } else {
            for (const string &next : preds[curr]) {
                traverse(target, next, stk, result, preds);
            }
        }
        stk.pop_back();
    }
    
    vector<string> getNext(const string &str, const set<string> &wordlist)
	{
		vector<string> ret;
		int n = str.length();
		for (int i = 0; i < n; i++)
		{
			string temp = str;
			char ch = str[i];
			for (char c = 'a'; c <= 'z'; c++)
			{
				if (c != ch)
				{
					temp[i] = c;
					if (wordlist.find(temp) != wordlist.end())
					{
						ret.push_back(temp);
					}
				}
			}
		}
		return ret;
	}
};
