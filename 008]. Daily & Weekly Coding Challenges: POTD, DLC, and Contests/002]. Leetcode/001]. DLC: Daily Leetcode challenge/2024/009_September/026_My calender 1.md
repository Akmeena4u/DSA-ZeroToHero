### Problem: **My Calendar I** (LeetCode #729)

You are asked to implement a calendar where you can add a new event if it doesn't cause a "double booking." A **double booking** occurs when two events overlap, meaning their time intervals have a non-empty intersection.

An event is represented by a start time and an end time. The event occupies the half-open interval `[start, end)`, meaning it includes the `start` but **excludes** the `end`. 

The task is to implement a class `MyCalendar` that:
- Initializes the calendar with no bookings.
- Has a method `book(start, end)` that returns `true` if an event can be booked without overlapping existing events and `false` otherwise.

### Constraints:
- `0 <= start < end <= 10^9`
- At most 1000 calls to `book` will be made.

### Example:
```cpp
MyCalendar myCalendar = new MyCalendar();
myCalendar.book(10, 20); // return True
myCalendar.book(15, 25); // return False (overlap with 10-20)
myCalendar.book(20, 30); // return True (no overlap)
```

### Approaches:

---

#### **Approach 1: Brute Force**
- **Idea:** Store each event in a vector. When booking a new event, check if it overlaps with any of the already booked events by iterating over all existing bookings.
- **Complexity:**
  - Time Complexity: `O(n^2)` — for each booking, we iterate over the existing bookings.
  - Space Complexity: `O(n)` — to store the events.

##### Code:
```cpp
typedef pair<int, int> P;
class MyCalendar {
public:
    // Vector to store all booked events
    vector<P> calendar;

    MyCalendar() { }

    // Method to book an event
    bool book(int start, int end) {
        // Iterate through all existing bookings
        for (int i = 0; i < calendar.size(); i++) {
            P curr = calendar[i];
            // Check if the new event overlaps with an existing one
            if (!(end <= curr.first || start >= curr.second)) {
                return false; // Overlap detected
            }
        }
        // No overlap, add the event
        calendar.push_back({start, end});
        return true;
    }
};
```
---

#### **Approach 2: Using `set` with `lower_bound`**
- **Idea:** Use a `set` to store the events as pairs of start and end times. 
  - When booking a new event, use `lower_bound` to find the first event starting after or at the same time as the new event. 
  - Check if the new event overlaps with either the next or the previous event.
- **Complexity:**
  - Time Complexity: `O(nlogn)` — insertion and finding the correct position using `set` operations.
  - Space Complexity: `O(n)` — to store the events.

##### Code:
```cpp
class MyCalendar {
public:
    // Set to store pairs of start and end times
    set<pair<int, int>> st;

    MyCalendar() { }

    bool book(int start, int end) {
        // Find the first event that starts at or after the current event
        auto it = st.lower_bound({start, end});

        // Check if the new event overlaps with the next event
        if (it != st.end() && it->first < end) {
            return false; // Overlapping, cannot book
        }

        // Check if the new event overlaps with the previous event
        if (it != st.begin()) {
            auto prevIt = prev(it);
            if (start < prevIt->second) {
                return false; // Overlapping with the previous event
            }
        }

        // No overlap, insert the event
        st.insert({start, end});
        return true;
    }
};
```
---

#### **Approach 3: Using `set` with `upper_bound`**
- **Idea:** Use `upper_bound` to check if an event can be inserted in the set without overlap. This method reverses the order of the pair (i.e., `{end, start}`) to find the right event using `upper_bound`.
- **Complexity:**
  - Time Complexity: `O(nlogn)` — set operations for insertion and search.
  - Space Complexity: `O(n)` — to store the events.

##### Code:
```cpp
class MyCalendar {
public:
    // Set to store pairs of {end, start} times
    set<pair<int, int>> st;

    MyCalendar() { }

    bool book(int start, int end) {
        // Find the event with the smallest end time greater than `end`
        auto it = st.upper_bound({start, end});

        // If it exists, check if the end time of the new event conflicts
        if (it != st.end() && end > it->second) {
            return false; // Overlapping
        }

        // No overlap, insert the event (store {end, start})
        st.insert({end, start});
        return true;
    }
};
```
---

### Summary:
- **Approach 1 (Brute Force):** Simple but inefficient for larger inputs, `O(n^2)` time complexity.
- **Approach 2 (`set` with `lower_bound`):** Efficient solution with `O(nlogn)` time complexity. It checks overlaps with both the previous and next events.
- **Approach 3 (`set` with `upper_bound`):** Similar to approach 2, but it reverses the pair to find the correct insertion point using `upper_bound`. Also `O(nlogn)`.

In practice, Approach 2 is widely used due to its straightforward implementation and efficient overlap checking with both previous and next events.
