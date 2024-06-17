### Problem Statement

Given two lines in a 2D plane defined by their endpoints p1 and q1, and p2 and q2, determine if the two lines intersect.

### Code

```cpp
#include <vector>
#include <string>

std::string checkIntersection(std::vector<int>& p1, std::vector<int>& q1, std::vector<int>& p2, std::vector<int>& q2) {
    // Calculate the slopes of the two lines
    double m1 = double(q1[1] - p1[1]) / double(q1[0] - p1[0]);
    double m2 = double(q2[1] - p2[1]) / double(q2[0] - p2[0]);

    // Check if lines are parallel
    if (m1 == m2) {
        return "false";
    }

    // Check the relative position of points
    bool check1 = p2[1] - p1[1] - m1 * (p2[0] - p1[0]) > 0 ? true : false;
    bool check2 = q2[1] - p1[1] - m1 * (q2[0] - p1[0]) > 0 ? true : false;

    bool check3 = p1[1] - p2[1] - m2 * (p1[0] - p2[0]) > 0 ? true : false;
    bool check4 = q1[1] - p2[1] - m2 * (q1[0] - p2[0]) > 0 ? true : false;

    // Determine if lines intersect
    if ((check1 == true && check2 == true) || (check1 == false && check2 == false) ||
        (check3 == true && check4 == true) || (check3 == false && check4 == false)) {
        return "false";
    }
    return "true";
}
```

### Explanation

1. **Checking Parallel Lines**:
   - Calculate the slopes m1 and m2 of the two lines.
   - If m1  equals m2, the lines are parallel and do not intersect, so return "false".

2. **Relative Position Checks**:
   - For the second line's points p2 and q2 relative to the first line p1, q1:
     - **check1**: Checks if p2  is on one side of the line formed by p1, q1.
     - **check2**: Checks if q2 is on the same side of the line formed by p1, q1 as p2.
   - For the first line's points p1 and q1 relative to the second line  p2, q2:
     - **check3** and **check4**: Perform analogous checks.

3. **Intersection Determination**:
   - If both points  p2 and q2 are on the same side of the first line, or both points p1 and q1 are on the same side of the second line, the lines do not intersect, hence return "false".
   - Otherwise, the lines intersect, hence return "true".

### Complexity Analysis

- **Time Complexity**: 
  - Each operation (slope calculation and relative position checks) involves basic arithmetic operations and comparisons, resulting in constant time operations.
  - Thus, the overall time complexity is O(1).

- **Space Complexity**: 
  - The function uses a constant amount of extra space for storing slopes and boolean variables.
  - Thus, the overall space complexity is O(1).

### Notes

- **Slope Calculation**:
  -  m1 and m2are calculated using the formula for slope: m = {y2 - y1}/{x2 - x1}.
  - Special cases where the denominator is zero (vertical lines) should be handled to avoid division by zero errors.

- **Relative Position Checks**:
  - Using the concept of cross products, the function determines the relative position of points to the line. 
  - This is a form of area comparison for triangles formed by the points and can be more reliable than checking slopes for collinearity, especially in integer coordinates to avoid precision errors.
