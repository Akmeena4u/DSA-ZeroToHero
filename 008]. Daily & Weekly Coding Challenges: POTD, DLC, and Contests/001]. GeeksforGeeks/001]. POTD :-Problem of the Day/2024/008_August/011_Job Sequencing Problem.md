### Job Sequencing Problem

**Problem Statement:**

You are given a set of `n` jobs, where each job has a unique ID, a deadline, and a profit associated with it. Each job takes exactly one unit of time to complete, and only one job can be scheduled at a time. The objective is to find the maximum profit that can be earned by scheduling the jobs within their respective deadlines.

You need to return two things:
1. The maximum number of jobs that can be completed.
2. The maximum profit that can be earned.

**Example:**

**Input:** `Jobs = [[1,4,20], [2,1,1], [3,1,40], [4,1,30]]`

**Output:** `2 60`

**Explanation:** 
- Job 3 (profit = 40) can be scheduled in slot 1.
- Job 1 (profit = 20) can be scheduled in slot 4 (or earlier).
- Total profit = 40 + 20 = 60.

---

### Intuition:

To solve this problem, the key idea is to maximize the profit while respecting the job deadlines. We should consider jobs that offer the highest profit first, and then schedule them in the latest possible time slot within their deadline. This greedy approach ensures that we maximize profit by filling the closest available slots to the deadline.

### Problem Pattern:

This problem can be classified under the **Greedy Algorithm** category because:
- We are making a locally optimal choice at each step (choosing the job with the highest profit that fits in the schedule).
- The globally optimal solution (maximum profit) is achieved by these local optimizations.

### Algorithm:

1. **Sort the Jobs by Profit**: Sort all jobs in decreasing order of their profit. This way, we prioritize jobs that give the highest return.

2. **Find Maximum Deadline**: Identify the maximum deadline across all jobs. This helps in creating a schedule that respects deadlines.

3. **Create a Slot Array**: Use an array to keep track of which time slots are filled. The size of this array is equal to the maximum deadline. Initialize all slots as empty (`-1`).

4. **Schedule Jobs**:
   - Iterate over each job (in the sorted order).
   - Try to schedule it in the latest available slot before its deadline.
   - If a slot is available, assign the job to that slot and update the total profit and job count.

5. **Return Results**: After processing all jobs, return the total number of jobs done and the total profit.

### Code Implementation:

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Job {
    int id;
    int dead;  // Deadline
    int profit;
};

class Solution {
public:
    static bool comparison(Job a, Job b) {
        return (a.profit > b.profit);  // Sort jobs in decreasing order of profit
    }

    vector<int> JobScheduling(Job arr[], int n) {
        // Step 1: Sort jobs by profit in decreasing order
        sort(arr, arr + n, comparison);

        // Step 2: Find the maximum deadline
        int maxDeadline = arr[0].dead;
        for (int i = 1; i < n; i++) {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }

        // Step 3: Create a slot array to keep track of free time slots
        int slot[maxDeadline + 1];
        for (int i = 0; i <= maxDeadline; i++)
            slot[i] = -1;  // Initialize all slots to be free

        // Step 4: Iterate over each job to find a slot
        int countJobs = 0, jobProfit = 0;

        for (int i = 0; i < n; i++) {
            for (int j = arr[i].dead; j > 0; j--) {
                if (slot[j] == -1) {  // If the slot is free
                    slot[j] = i;      // Assign this job to the slot
                    countJobs++;      // Increment job count
                    jobProfit += arr[i].profit;  // Add profit
                    break;
                }
            }
        }

        // Return the number of jobs done and total profit
        return {countJobs, jobProfit};
    }
};

int main() {
    Job arr[] = {{1, 4, 20}, {2, 1, 1}, {3, 1, 40}, {4, 1, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);

    Solution sol;
    vector<int> result = sol.JobScheduling(arr, n);
    cout << "Number of jobs done: " << result[0] << "\n";
    cout << "Maximum profit: " << result[1] << "\n";

    return 0;
}
```

### Dry Run:

Consider the input `Jobs = [[1, 4, 20], [2, 1, 1], [3, 1, 40], [4, 1, 30]]`.

1. **Sorting**: After sorting by profit, the jobs are `[[3, 1, 40], [4, 1, 30], [1, 4, 20], [2, 1, 1]]`.

2. **Max Deadline**: The maximum deadline is `4`.

3. **Slot Array**: Initialize `slot[5]` to `[-1, -1, -1, -1, -1]`.

4. **Job Scheduling**:
   - Job 3 is placed in slot 1 (first free slot before its deadline).
   - Job 4 cannot be placed because slot 1 is occupied.
   - Job 1 is placed in slot 4.
   - Job 2 cannot be placed because slot 1 is occupied.

   Result: `countJobs = 2`, `jobProfit = 60`.

### Complexity Analysis:

- **Time Complexity**: 
  - Sorting takes `O(n log n)`.
  - The job scheduling loop takes `O(n * maxDeadline)`.
  - Total: `O(n log n + n * maxDeadline)`.

- **Space Complexity**: 
  - The space required for the slot array is `O(maxDeadline)`.
  - Total: `O(maxDeadline)`.

---

This algorithm effectively balances time efficiency and simplicity, making it a practical solution for the job sequencing problem.
