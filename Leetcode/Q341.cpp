/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    using Iter = vector<NestedInteger>::iterator;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        stk = stack<pair<Iter, Iter>>();
        stk.push(make_pair(nestedList.begin(), nestedList.end()));
        advance();
    }

    // guarantee that the stack top points to the next integer
    int next() {
        assert(hasNext());
        assert(stk.top().first->isInteger());
        int result = stk.top().first->getInteger();
        //
        ++stk.top().first;
        advance();
        //
        return result;
    }

    bool hasNext() {
        return !stk.empty();
    }
    
private:
    // pair of the iterator and the end of the vector
    stack<pair<Iter, Iter>> stk;
    
    void advance() {
        while (!stk.empty()) {
            auto curr = stk.top();
            if (curr.first == curr.second) {
                stk.pop();
                if (!stk.empty()) {
                    ++stk.top().first;
                }
                continue;
            }
            if (curr.first->isInteger()) {
                break;
            } else {
                auto& child = curr.first->getList();
                stk.push(make_pair(child.begin(), child.end()));
            }
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

