
### Problem Statement

Given a square grid of size \( N \times N \), each cell contains an integer cost representing the cost to traverse through that cell. The task is to find a path from the top-left cell to the bottom-right cell with the minimum total cost. You can move up, down, left, or right from any cell.

### Approach

The problem can be solved efficiently using Dijkstra's algorithm, which is well-suited for finding the shortest paths in graphs with non-negative weights.

### Algorithm

1. **Initialize Data Structures**:
   - **Distance Matrix**: `dis` which stores the minimum cost to reach each cell from the top-left corner. Initialize it with infinity (`INT_MAX`) except for the starting cell (top-left corner) which is initialized with its own cost.
   - **Priority Queue**: `pq` to process cells with the minimum cost first. It stores `Custom` objects which hold the cell coordinates and the current minimum distance.
   
2. **Priority Queue Operations**:
   - Start by pushing the top-left cell (0,0) with its cost into the priority queue.
   - While the priority queue is not empty, extract the cell with the minimum cost.

3. **Process Neighbors**:
   - For the current cell, check all its valid neighbors (up, down, left, right).
   - If moving to a neighbor reduces its current known cost, update the cost and push the neighbor into the priority queue with the new cost.

4. **End Condition**:
   - Continue until the priority queue is empty. The minimum cost to reach the bottom-right cell will be in the distance matrix at the bottom-right corner.

### Detailed Code Explanation

```cpp
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Custom structure to hold the cell coordinates and distance
struct Custom {
    int x, y, dis;
    Custom(int x, int y, int dis) : x(x), y(y), dis(dis) {}
};

// Comparator to use with the priority queue
struct Compare {
    bool operator()(Custom const& a, Custom const& b) {
        return a.dis > b.dis;  // Min-heap based on distance
    }
};

bool valid(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

int minimumCostPath(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
    priority_queue<Custom, vector<Custom>, Compare> pq;
    
    // Directions: up, right, down, left
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    
    // Initialize starting cell
    dis[0][0] = grid[0][0];
    pq.push(Custom(0, 0, grid[0][0]));
    
    while (!pq.empty()) {
        Custom curr = pq.top();
        pq.pop();
        
        // Process each neighboring cell
        for (int i = 0; i < 4; ++i) {
            int nbrX = curr.x + dx[i];
            int nbrY = curr.y + dy[i];
            
            if (valid(nbrX, nbrY, n, m)) {
                // Update distance if a shorter path is found
                if (curr.dis + grid[nbrX][nbrY] < dis[nbrX][nbrY]) {
                    dis[nbrX][nbrY] = curr.dis + grid[nbrX][nbrY];
                    pq.push(Custom(nbrX, nbrY, dis[nbrX][nbrY]));
                }
            }
        }
    }
    
    // Return the minimum cost to reach the bottom-right cell
    return dis[n - 1][m - 1];
}
```

### Key Points

- **Priority Queue**: Used to always process the cell with the currently known smallest cost.
- **Distance Matrix**: Keeps track of the minimum cost to reach each cell.
- **Neighbor Validity**: Ensure that movements stay within the bounds of the grid.
- **Dijkstra's Algorithm**: Suitable for this problem due to the non-negative weights and the need for shortest path calculation.

