class FreqStack {
public:
    FreqStack() {
        freqMap = unordered_map<int, int>();
        intMap = unordered_map<int, stack<int>>();
        maxFreq = 0;
    }
    
    void push(int x) {
        if (freqMap.find(x) == freqMap.end()) freqMap[x] = 0;
        freqMap[x]++;
        int f = freqMap[x];
        if (intMap.find(f) == intMap.end()) intMap[f] = stack<int>();
        intMap[f].push(x);
        maxFreq = max(maxFreq, f);
    }
    
    int pop() {
        int f = maxFreq;
        int x = intMap[f].top();
        intMap[f].pop();
        freqMap[x]--;
        if (intMap[f].empty()) maxFreq--;
        return x;
    }
    
private:
    unordered_map<int, int> freqMap; // map from integer to frequency
    unordered_map<int, stack<int>> intMap; // map from frequency to integer
    int maxFreq; // maximum frequency
    static int max(int a, int b) {
        return a > b ? a : b;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */