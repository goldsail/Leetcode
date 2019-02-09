class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() == 0 || s.size() == 0) {
            return "";
        }
        
        this->desirable_windows = priority_queue<Window>();
        this->s_count = array<int, CHAR_RANGE>();
        this->t_count = array<int, CHAR_RANGE>();
        for (int i = 0; i < t.size(); i++) {
            t_count[t[i]]++;
        }
        
        int left = 0;
        int right = 0;
        
        while (true) {
            
            bool flag;
            do {
                s_count[s[right]]++;
                right++;
                flag = isDesirable();
            } while (right < s.size() && !flag);
            
            if (flag) {
                 do {
                    s_count[s[left]]--;
                    left++;
                } while (left < right && isDesirable());
                
                Window window;
                window.start = left - 1;
                window.end = right;
                desirable_windows.push(window);
            } else {
                break;
            }
            
        }
        
        if (desirable_windows.empty()) {
            return string("");
        } else {
            Window result = desirable_windows.top();
            return s.substr(result.start, result.getLength());
        }
    }
    
private:
    struct Window {
        int start;
        int end;
        int getLength() const {
            return this->end - this->start;
        }
        bool operator< (const Window &rhs) const {
            return this->getLength() > rhs.getLength();
        }
    };
    
    priority_queue<Window> desirable_windows;
    constexpr static int CHAR_RANGE = 0x80;
    array<int, CHAR_RANGE> s_count;
    array<int, CHAR_RANGE> t_count;
    
    bool isDesirable() const {
        for (int i = 0; i < CHAR_RANGE; i++) {
            if (this->s_count[i] < this->t_count[i]) {
                return false;
            }
        }
        return true;
    }
};