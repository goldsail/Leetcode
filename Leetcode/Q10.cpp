class Solution {
public:
    bool isMatch(string s, string p) {
        
        // preprocess the string p: split characters and stars
        char *p_ = new char[p.size()];
        bool *p_stars = new bool[p.size()];
        int p_length = 0;
        for (int i = 0; i < p.size(); i++) {
            if (p[i] == '*') {
                p_stars[p_length - 1] = true;
            } else {
                p_[p_length] = p[i];
                p_stars[p_length] = false;
                p_length++;
            }
        }
        
        bool result = this->isMatch_(s.size(), s.data(), p_length, p_, p_stars);
        
        delete[] p_;
        delete[] p_stars;
        
        return result;
    }
    
private:
    bool isMatch_(int s_length, const char *s, int p_length, const char *p, const bool *p_stars) {
        
        bool result = false;
        
        // create the 2D table for dynamic programming
        bool **table = new bool*[p_length + 1];
        for (int i = 0; i < p_length + 1; i++) {
            table[i] = new bool[s_length + 1];
        }
        
        // initialize the table's first row and first column
        table[0][0] = true;
        for (int j = 0; j < s_length; j++) {
            table[0][j + 1] = false;
        }
        for (int i = 0; i < p_length; i++) {
            table[i + 1][0] = table[i][0] && p_stars[i];
        }
        
        // print_table_(table, p_length + 1, s_length + 1);
        
        // calculate other entries using DP
        for (int i = 0; i < p_length; i++) {
            for (int j = 0; j < s_length; j++) {
                
                bool temp = p[i] == '.' || p[i] == s[j];
                
                // std::cout << temp;
                
                if (p_stars[i]) {
                    table[i + 1][j + 1] = table[i][j + 1] || (table[i][j] && temp) || (table[i + 1][j] && temp);
                } else {
                    table[i + 1][j + 1] = (table[i][j] && temp);
                }
                
                // print_table_(table, p_length + 1, s_length + 1);
            }
        }
        
        result = table[p_length][s_length];
        
        // destroy the 2D table
        for (int i = 0; i < p_length + 1; i++) {
            delete[] table[i];
        }
        delete[] table;
        return result;
    }
    
    void print_table_(bool **table, int m, int n) {
        std::cout << endl;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << (table[i][j] ? 'T' : 'F');
            }
            std::cout << endl;
        }
    }
};