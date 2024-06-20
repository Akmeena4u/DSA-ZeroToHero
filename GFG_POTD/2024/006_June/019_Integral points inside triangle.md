

```cpp
#include <iostream>
#include <cmath>

// Problem Statement:
// Given three points A, B, and C on a 2D plane, determine the number of integer (lattice) points
// that lie strictly inside the triangle formed by these points. Lattice points are points with
// integer coordinates. The boundary points are not included.

// Approach:
// To solve this problem, we use Pick's Theorem. Pick's Theorem relates the area of a simple polygon
// whose vertices are lattice points to the number of lattice points inside the polygon and on its boundary.
// The theorem is stated as:
//      A = I + B / 2 - 1
// Where:
//      A is the area of the polygon.
//      I is the number of interior lattice points.
//      B is the number of boundary lattice points.
// From Pick's Theorem, we can derive the number of interior points (I) as:
//      I = A - B / 2 + 1

// To apply this theorem, we need to:
// 1. Calculate the area A of the triangle.
// 2. Calculate the number of boundary points B.

// Calculating the Area of the Triangle:
// We use the Shoelace formula (also known as Gauss's area formula) to calculate the area of the triangle formed by points A, B, and C:
//      Area = 1/2 * | x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2) |

// Calculating the Boundary Points:
// We need to find the number of lattice points on the boundary of the triangle. This involves:
// - Counting points on each side of the triangle.
// - Using the greatest common divisor (GCD) to determine the number of lattice points on each line segment.
// For a line segment between two points (x1, y1) and (x2, y2):
// - If x1 = x2, then the number of lattice points is |y2 - y1|.
// - If y1 = y2, then the number of lattice points is |x2 - x1|.
// - Otherwise, the number of lattice points is gcd(|x2 - x1|, |y2 - y1|).

class Solution {
public:
    class Point {
    public:
        long x, y;
        Point(long x, long y) : x(x), y(y) {}
    };
    
    long long internalCount(long long p[], long long q[], long long r[]) {
        Point P(p[0], p[1]);
        Point Q(q[0], q[1]);
        Point R(r[0], r[1]);

        long boundary = boundaryPoint(P, Q) + boundaryPoint(Q, R) + boundaryPoint(R, P) + 3;
        long area = std::abs(P.x * (Q.y - R.y) + Q.x * (R.y - P.y) + R.x * (P.y - Q.y)) / 2;
        long internalPoints = area + 1 - boundary / 2;
        return internalPoints;
    }

    long boundaryPoint(Point p, Point q) {
        if (p.x == q.x) return std::abs(p.y - q.y);
        if (p.y == q.y) return std::abs(p.x - q.x);
        return gcd(std::abs(p.x - q.x), std::abs(p.y - q.y));
    }

    long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};

int main() {
    Solution sol;
    long long p[] = {1, 1};
    long long q[] = {4, 1};
    long long r[] = {2, 3};

    std::cout << "Integral points inside the triangle: " << sol.internalCount(p, q, r) << std::endl;
    return 0;
}
```

### Explanation of Code

1. **Point Class**: Represents a point in 2D space with `x` and `y` coordinates.
2. **internalCount Function**: Uses Pick's Theorem to calculate the number of internal lattice points using the provided vertices of the triangle.
3. **boundaryPoint Function**: Calculates the number of lattice points on the boundary between two points, including the endpoints.
4. **gcd Function**: Calculates the greatest common divisor of two numbers using a loop.
5. **main Function**: Creates an instance of `Solution`, defines three points of the triangle, and prints the number of internal points.
