class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.empty()) return vector<vector<int>>();
        return getSkyline(buildings.begin(), buildings.end());
    }
    
private:
    
    using Point = vector<int>;
    using Rect = vector<int>;
    
    vector<Point> getSkyline(vector<Rect>::iterator begin, vector<Rect>::iterator end) {
        if (end - begin == 1) { // trivial case
            vector<Point> result;
            Rect rect = *begin;
            result.push_back(Point{ rect[0], rect[2] });
            result.push_back(Point{ rect[1], 0 });
            return result;
        } else { // recursive cases
            auto mid = begin + (end - begin) / 2;
            vector<Point> s1 = getSkyline(begin, mid);
            vector<Point> s2 = getSkyline(mid, end);
            return mergeSkyline(s1, s2);
        }
    }
    
    vector<Point> mergeSkyline(const vector<Point>& s1, const vector<Point>& s2) {
        
        vector<Point> result;
        
        int p1 = 0, p2 = 0; // position index
        int h1 = 0, h2 = 0; // current height
        
        while (p1 < s1.size() && p2 < s2.size()) {
            
            // case 1: current position in s1 is on the left 
            if (s1[p1][0] < s2[p2][0]) {
                h1 = s1[p1][1];
                result.push_back(Point{ s1[p1][0], max(h1, h2) });
                p1++;
            }
            
            // case 2: current position in s2 is on the left
            else if (s1[p1][0] > s2[p2][0]) {
                h2 = s2[p2][1];
                result.push_back(Point{ s2[p2][0], max(h1, h2) });
                p2++;
            }
            
            // case 3: current position in s1 is same as that in s2
            else {
                h1 = s1[p1][1];
                h2 = s2[p2][1];
                result.push_back(Point{ s1[p1][0], max(h1, h2) });
                p1++;
                p2++;
            }
        }
        
        // if the loop terminates with s2, make sure to read the rest of s1
        while (p1 < s1.size()) {
            result.push_back(s1[p1]);
            p1++;
        }
        
        // if the loop terminates with s1, make sure to read the rest of s2
        while (p2 < s2.size()) {
            result.push_back(s2[p2]);
            p2++;
        }
        
        // remove consecutive horizontal lines of equal height
        result.erase(unique(result.begin(), result.end(), [](const Point& a, const Point& b) {
            return a[1] == b[1];
        }), result.end());
        
        
        return result;
    }
};