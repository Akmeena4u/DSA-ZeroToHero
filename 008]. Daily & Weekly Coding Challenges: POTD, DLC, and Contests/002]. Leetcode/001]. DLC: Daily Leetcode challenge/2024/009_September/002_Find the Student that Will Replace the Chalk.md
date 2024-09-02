
**Problem Statement:**

There are `n` students in a class numbered from `0` to `n - 1`. The teacher will give each student a problem, starting with student number zero, then student number one, and so on. After that, the teacher will restart the process and start again from student number zero.

You are given a zero-indexed integer array `chock` and an integer `k`. Initially, there are `k` pieces of chalk. The array `chock[i]` represents the number of chalk pieces needed by student `i` to solve their problem.

However, if the current number of chalk pieces is strictly less than `chock[i]`, then the student at index `i` will be asked to replace the chalk.

Return the index of the student who will replace the chalk pieces.

**Example:**

Let's understand this with an example:
- The array `chock` is `[5, 1, 5]` and the total number of chalk pieces is `22`.

Initially:
- Student 0 needs 5 pieces of chalk, so 22 - 5 = 17 pieces of chalk remain.
- Student 1 needs 1 piece of chalk, so 17 - 1 = 16 pieces of chalk remain.
- Student 2 needs 5 pieces of chalk, so 16 - 5 = 11 pieces of chalk remain.

The teacher then starts again from Student 0:
- Student 0 needs 5 pieces of chalk, so 11 - 5 = 6 pieces of chalk remain.
- Student 1 needs 1 piece of chalk, so 6 - 1 = 5 pieces of chalk remain.
- Student 2 needs 5 pieces of chalk, so 5 - 5 = 0 pieces of chalk remain.

Now, the chalk is finished. When we come back to Student 0, they need 5 pieces of chalk but there are none left. Therefore, Student 0 will have to replace the chalk.

So, the answer is index `0`.

**Approach 1: Simulation**

We can solve the problem using a simple simulation approach. This approach iterates over the array `chock` and keeps track of the remaining chalk. If at any point the remaining chalk is less than the chalk needed by the current student, we return that student's index. Otherwise, we continue until we find the student who will replace the chalk.

Here's the code for the simulation approach:

```cpp
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        while(true) {
            for(int i = 0; i < chalk.size(); i++) {
                if(k < chalk[i]) {
                    return i;
                }
                k -= chalk[i];
            }
        }

        return -1;
    }
};
```

**Approach 2: Using Remainder**

To optimize the solution, we can calculate the total number of chalk pieces required in one full iteration and use the remainder to directly determine which student will replace the chalk. This approach reduces the complexity and makes the solution more efficient.

Here's the code for the optimized approach using the remainder:

```cpp
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();

        long long totalChalkSum = 0; // Total chalks required in one iteration
        for(int &chalkReq : chalk) { // O(n)
            totalChalkSum += chalkReq;
        }

        // Number of full iterations possible = k/totalChalkSum
        int remainChalk = k % totalChalkSum;

        for(int i = 0; i < n; i++) { // O(n)
            if(remainChalk < chalk[i]) {
                return i;
            }

            remainChalk -= chalk[i];
        }

        return -1;
    }
};
```


**Time Complexity Analysis:**

- The time complexity of the simulation approach is `O(k * n)`, where `k` is the total number of chalk pieces and `n` is the number of students.
- The time complexity of the optimized approach using the remainder is `O(n)`.

