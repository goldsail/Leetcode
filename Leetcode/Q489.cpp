/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

struct State {
    int x;
    int y;
    int state;
    bool flag;
    State(int x, int y) : x(x), y(y), state(0), flag(false) {}
};

// Idea:
// Keep robot heading to north at all times.
// Use stack to emulate recursion.
// Use state and flag to remember the recursive calls inside if-conditions.

class Solution {
public:
    void cleanRoom(Robot& robot) {
        vector<State> stk;
        unordered_set<string> visited;
        stk.push_back(State(0, 0));
        visited.insert("0,0");
        while (!stk.empty()) {
            State &curr = stk.back();
            int x, y;
            switch (curr.state) {
                case 0:
                    // visit north
                    x = curr.x;
                    y = curr.y + 1;
                    curr.flag = false;
                    curr.state++;
                    if (visited.find(encode(x, y)) == visited.end()) {
                        visited.insert(encode(x, y));
                        if (robot.move()) {
                            curr.flag = true;
                            stk.push_back(State(x, y));
                        }
                    }
                    break;
                case 1:
                    // visit east
                    if (curr.flag) {
                        // move back from previous location (north)
                        robot.turnRight();
                        robot.turnRight();
                        robot.move();
                        robot.turnLeft();
                        robot.turnLeft();
                    }
                    x = curr.x + 1;
                    y = curr.y;
                    curr.flag = false;
                    curr.state++;
                    if (visited.find(encode(x, y)) == visited.end()) {
                        visited.insert(encode(x, y));
                        robot.turnRight();
                        if (robot.move()) {
                            robot.turnLeft();
                            curr.flag = true;
                            stk.push_back(State(x, y));
                        } else {
                            robot.turnLeft();
                        }
                    }
                    break;
                case 2:
                    // visit south
                    if (curr.flag) {
                        // move back from previous location (east)
                        robot.turnLeft();
                        robot.move();
                        robot.turnRight();
                    }
                    x = curr.x;
                    y = curr.y - 1;
                    curr.flag = false;
                    curr.state++;
                    if (visited.find(encode(x, y)) == visited.end()) {
                        visited.insert(encode(x, y));
                        robot.turnRight();
                        robot.turnRight();
                        if (robot.move()) {
                            robot.turnLeft();
                            robot.turnLeft();
                            curr.flag = true;
                            stk.push_back(State(x, y));
                        } else {
                            robot.turnLeft();
                            robot.turnLeft();
                        }
                    }
                    break;
                case 3:
                    // visit west
                    if (curr.flag) {
                        // move back from previous location (south)
                        robot.move();
                    }
                    x = curr.x - 1;
                    y = curr.y;
                    curr.flag = false;
                    curr.state++;
                    if (visited.find(encode(x, y)) == visited.end()) {
                        visited.insert(encode(x, y));
                        robot.turnLeft();
                        if (robot.move()) {
                            robot.turnRight();
                            curr.flag = true;
                            stk.push_back(State(x, y));
                        } else {
                            robot.turnRight();
                        }
                    }
                    break;
                case 4:
                    // trace back
                    if (curr.flag) {
                        // move back from previous location (west)
                        robot.turnRight();
                        robot.move();
                        robot.turnLeft();
                    }
                    robot.clean();
                    stk.pop_back();
                    break;
            }
        }
    }
    
private:
    string encode(int x, int y) {
        return to_string(x) + ',' + to_string(y);
    }
};
