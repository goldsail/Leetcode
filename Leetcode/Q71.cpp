class Solution {
public:
    string simplifyPath(string path) {
        vector<string> pathStack;
        
        string temp;
        int i = 0;
        while (i < path.size()) {
            while (i < path.size() && path[i] == '/') {
                i++;
            }
            
            if (i == path.size()) {
                break;
            }
            
            temp = "";
            do {
                temp += path[i];
                i++;
            } while (i < path.size() && path[i] != '/');
            
            if (temp == ".") {
                ;
            } else if (temp == "..") {
                if (!pathStack.empty()) {
                    pathStack.pop_back();
                }
            } else {
                pathStack.push_back(temp);
            }
        }
        
        if (pathStack.empty()) {
            return "/";
        }
        
        string result;
        for (string s : pathStack) {
            result += '/';
            result += s;
        }
        return result;
    }
    
};