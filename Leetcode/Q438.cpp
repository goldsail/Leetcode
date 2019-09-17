class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        assert(!p.empty());
        array<int, 26> arr = {0};
        for (char c : p) {
            assert(c >= 'a' && c <= 'z');
            arr[c - 'a']--;
        }
        //
        vector<int> result;
        auto check = [&result, &arr](int pos) -> void {
            for (int x : arr) {
                if (x != 0) return;
            }
            result.push_back(pos);
        };
        if (s.size() < p.size()) return result;
        //
        for (int i = 0; i < p.size(); i++) {
            char c = s[i];
            assert(c >= 'a' && c <= 'z');
            arr[c - 'a']++;
        }
        check(0);
        //
        for (int i = 0; i + p.size() < s.size(); i++) {
            char c = s[i + p.size()];
            assert(c >= 'a' && c <= 'z');
            arr[c - 'a']++;
            arr[s[i] - 'a']--;
            check(i + 1);
        }
        return result;
    }
};

