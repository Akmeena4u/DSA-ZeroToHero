### **Problem: Find Missing Observations**

You are given `n + m` observations of 6-sided dice rolls, where `n` rolls are missing, and you have the observations of `m` rolls. You also know the average value of all `n + m` rolls. Your task is to find the `n` missing observations such that the average of all `n + m` rolls matches the given mean. If no such observations exist, return an empty array.

### **Approach:**

1. **Calculate Total Sum:**
   - Compute the total sum of all `n + m` rolls using the given mean:  
     `total_sum = mean*(n + m)`
    
2. **Determine Missing Sum:**
   - Subtract the sum of known rolls from the total sum to find the sum of missing rolls:  
     `missing_sum = total_sum - sum of known rolls`

3. **Check Validity:**
   - Ensure that the `missing_sum` is within the range of possible sums for `n` dice (i.e., between `n` and `6 \times n`). If not, return an empty array.

4. **Distribute Missing Rolls:**
   - Compute the average value for the missing rolls:  
     `avg = missing_sum\n`
   - Distribute the `missing_sum` across `n` rolls as evenly as possible. Adjust for any remainder.


### **C++ Solution:**

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int totalSum = mean * (n + m); // Total sum of all rolls
        int sumKnownRolls = 0;
        for (int roll : rolls) {
            sumKnownRolls += roll;
        }
        int missingSum = totalSum - sumKnownRolls;
        if (missingSum < n || missingSum > 6 * n) {
            return {}; // Return empty vector
        }
        int avg = missingSum / n;
        int remainder = missingSum % n;
        vector<int> result(n, avg);
        for (int i = 0; i < remainder; i++) {
            result[i]++;
        }
        return result;
    }
};
```

### **Summary:**

- **Calculate Total Sum** using the mean.
- **Find Missing Sum** by subtracting the sum of known rolls.
- **Check Validity**: Ensure the missing sum is within the possible range.
- **Distribute Rolls**: Compute average and adjust for any remainder.
