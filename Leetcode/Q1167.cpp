class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> heap;
        for (int x : sticks) heap.push(x);
        
        int count = 0;
        while (heap.size() > 1) {
            int x1 = heap.top();
            heap.pop();
            int x2 = heap.top();
            heap.pop();
            count += (x1 + x2);
            heap.push(x1 + x2);
        }
        return count;
    }
};
