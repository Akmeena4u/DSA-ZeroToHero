### Problem:  K Closest Points to Origin

**Description**:
Given an array of points where `points[i] = [xi, yi]` represents a point on the X-Y plane and an integer `k`, return the `k` closest points to the origin `(0, 0)`. The distance between two points on the X-Y plane is the Euclidean distance.

**Example**:
- **Input**: `points = [[1,3],[-2,2]], k = 1`
- **Output**: `[[-2, 2]]`

### Explanation

To solve the problem of finding the k closest points to the origin, we can utilize a max heap to keep track of the closest points.

### Detailed Steps:

1. **Define a Custom Comparator**:
   - We need a custom comparator for our priority queue (max heap) to compare the Euclidean distances of points from the origin. The comparator will compare the squared distances to avoid unnecessary floating-point operations.

```cpp
class comp {
public:
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        int distA = a.first * a.first + a.second * a.second;
        int distB = b.first * b.first + b.second * b.second;
        return distA > distB; // max heap
    }
};
```

2. **Solution Class**:
   - The main logic of finding the k closest points is implemented in the `kClosest` function.

```cpp
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

        // Insert all points into the max heap with their distances from the origin
        for (auto p : points) {
            pq.push({p[0], p[1]});
            // Ensure the heap only contains the k closest points
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // Extract the k closest points from the heap
        while (!pq.empty() && k--) {
            auto& top = pq.top();
            ans.push_back({top.first, top.second});
            pq.pop();
        }
        return ans;
    }
};
```


### Notes on Implementation

1. **Custom Comparator**:
   - We defined a `comp` class that overrides the `operator()` to compare two points based on their squared distances from the origin. This ensures we are always pushing the point with the largest distance out when the size of the heap exceeds `k`.

2. **Max Heap**:
   - We use a max heap (priority queue) to keep track of the `k` closest points. If the size of the heap exceeds `k`, we remove the point with the largest distance.

3. **Efficiency**:
   - This approach ensures that we are maintaining only the `k` closest points in the heap, which keeps our space complexity manageable and helps in efficiently finding the required points.

4. **Heap Size Management**:
   - The key operation is the conditional `pq.pop()` to maintain the heap size within the limit of `k` elements.

This approach ensures an efficient solution to the problem with a time complexity of O(N log k), where N is the number of points, and k is the number of closest points we need to find.
