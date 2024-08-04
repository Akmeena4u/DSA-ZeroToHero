## Problem: N Meetings in One Room

**Description:**
You are given the start and end times of `n` meetings in the form of two arrays, `start[]` and `end[]`. You need to find the maximum number of meetings that can be accommodated in a single meeting room, where only one meeting can be held at a time. Note that the start time of one chosen meeting cannot be equal to the end time of another chosen meeting.

### Example

**Input:**
- `n = 6`
- `start[] = [1, 3, 0, 5, 8, 5]`
- `end[] = [2, 4, 6, 7, 9, 9]`

**Output:**
- `4`

**Explanation:**
The maximum four meetings that can be held are `(1, 2)`, `(3, 4)`, `(5, 7)`, and `(8, 9)`.

## Solution Explanation

### Intuition
The core idea behind solving the problem is to select the maximum number of non-overlapping meetings that can fit into a single room. By following a greedy approach, we aim to maximize the number of meetings by always picking the next meeting that ends the earliest and is compatible with the last selected meeting. This way, we leave as much room as possible for future meetings.

### Problem Pattern
This problem follows the **Activity Selection Problem** pattern, where you are given a set of activities (meetings, in this case) with start and end times, and you need to select the maximum number of non-overlapping activities.


### Detailed Steps:

1. **Create a Structure to Store Meetings:**
   Define a structure `meeting` to hold the start time, end time, and original position of each meeting.

2. **Sort the Meetings:**
   Sort the meetings by their end times. If two meetings have the same end time, sort them by their original position. This helps in selecting meetings that end earliest, leaving more room for subsequent meetings.

3. **Select Meetings Using a Greedy Approach:**
   - Initialize the count of meetings that can be held.
   - Iterate through the sorted meetings, and for each meeting, check if it can be accommodated (i.e., its start time is after the last selected meeting's end time).

### Code Implementation:

```cpp
#include <bits/stdc++.h>
using namespace std;

struct meeting {
   int start;
   int end;
   int pos;
};

class Solution {
public:
    static bool comparator(struct meeting m1, meeting m2) {
        if (m1.end < m2.end) return true;
        else if (m1.end > m2.end) return false;
        else if (m1.pos < m2.pos) return true;
        return false;
    }
    
    // Function to find the maximum number of meetings that can be performed in a meeting room.
    int maxMeetings(int n, int s[], int e[]) {
        struct meeting meet[n];
        for (int i = 0; i < n; i++) {
            meet[i].start = s[i];
            meet[i].end = e[i];
            meet[i].pos = i + 1;
        }

        // Sort the meetings according to end times (and positions if end times are the same).
        sort(meet, meet + n, comparator);

        int limit = meet[0].end;
        int cnt = 1; // Initialize the count with the first meeting

        for (int i = 1; i < n; i++) {
            if (meet[i].start > limit) {
                limit = meet[i].end;
                cnt++;
            }
        }
        return cnt;
    }
};
```

### Complexity Analysis
1. **Time Complexity:**
   - Sorting the meetings takes \(O(n \log n)\).
   - Iterating through the meetings to select the maximum number of non-overlapping meetings takes \(O(n)\).
   - Hence, the overall time complexity is \(O(n \log n)\).

2. **Space Complexity:**
   - The space complexity is \(O(n)\) for storing the meetings.


By following this approach, you can efficiently determine the maximum number of non-overlapping meetings that can be scheduled in the given meeting room. This method ensures optimal use of the room's time by always selecting the meeting that leaves the maximum room for future meetings.
