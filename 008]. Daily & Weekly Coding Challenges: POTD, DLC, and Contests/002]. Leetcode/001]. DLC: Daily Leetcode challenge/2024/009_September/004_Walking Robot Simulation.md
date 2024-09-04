To solve the problem of simulating the walking robot on an infinite XY-plane, we can break down the solution into several steps. The robot starts at the origin (0, 0) facing north and receives a sequence of commands to move or turn. The robot must avoid obstacles and we need to calculate the maximum Euclidean distance squared that it reaches from the origin.

### Step-by-Step Approach:

1. **Define Directions:**
   The robot can face one of four directions: North, East, South, and West. We can represent these directions as vectors:
   - North: (0, 1) 
   - East: (1, 0)
   - South: (0, -1)
   - West: (-1, 0)
   
   These can be stored in a list and the current direction can be tracked using an index.

2. **Initial Setup:**
   - Start at position `(x, y) = (0, 0)` and facing North.
   - Convert the list of obstacles into a set of tuples for O(1) access time, which will allow us to quickly check if the next move hits an obstacle.

3. **Execute Commands:**
   - If the command is `-2`, turn left by moving counterclockwise in the direction list (decrement the index).
   - If the command is `-1`, turn right by moving clockwise in the direction list (increment the index).
   - If the command is a positive number `k`, move forward `k` units in the current direction, but stop if an obstacle is encountered.

4. **Calculate Distance:**
   After each move, calculate the Euclidean distance squared from the origin using the formula \(x^2 + y^2\) and update the maximum distance if the new distance is greater.

5. **Return the Maximum Distance:**
   After processing all commands, return the maximum distance squared.

### Example Implementation in cpp:

```cpp
//Simple Simulation
//T.C : O(m + n * maxValCommand), m = size of obstacles, n = size of commands
//S.C : O(m)
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> st;
        for(vector<int>& obs : obstacles) {
            string key = to_string(obs[0]) + "_" + to_string(obs[1]);
            st.insert(key);
        }

        int x = 0;
        int y = 0;
        int maxD = 0;

        //Pointing to North
        pair<int, int> dir = {0, 1}; //N

        for(int i = 0; i < commands.size(); i++) {
            if(commands[i] == -2) { //left 90 degree
                dir = {-dir.second, dir.first};
            } else if(commands[i] == -1) { //right 90 degree
                dir = {dir.second, -dir.first};
            } else { //move to the direction step by step
                for(int step = 0; step < commands[i]; step++) {
                    int newX = x + dir.first;
                    int newY = y + dir.second;

                    string nextKey = to_string(newX) + "_" + to_string(newY);

                    if(st.find(nextKey) != st.end()) {
                        break;
                    }

                    x = newX;
                    y = newY;
                }
            }

            maxD = max(maxD, x*x + y*y);
        }

        return maxD;
    }
};


```

### Example Run:

For the input `commands = [4,-1,3]` and `obstacles = []`:
- The robot moves north 4 units to `(0, 4)`.
- Turns right to face east.
- Moves east 3 units to `(3, 4)`.
- The maximum Euclidean distance squared from the origin is \(3^2 + 4^2 = 9 + 16 = 25\).

### Edge Cases:
- **Obstacles at the origin**: The robot cannot move if its first move is blocked.
- **Negative or out-of-bound commands**: The command values are bounded as per the problem description, ensuring valid inputs.

This solution efficiently simulates the robot's movements while checking for obstacles and calculating the maximum distance from the origin.
