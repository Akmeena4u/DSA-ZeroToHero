### Problem Understanding

**Objective**: Validate if a given string is a valid IPv4 address.

**IPv4 Address Format**:
- It is written as four decimal numbers separated by dots. For example, `192.168.1.1`.
- Each number should be between 0 and 255.
- Leading zeros in a number are not allowed (e.g., `01` is invalid).

### Intuition

1. **Structure**: An IPv4 address must have exactly four segments separated by three dots.
2. **Range**: Each segment (number) should be between 0 and 255.
3. **Leading Zeros**: Numbers should not start with a zero unless they are exactly '0'.

### Algorithm

1. **Initialize Counters**: Track the number of dots and the current segment being processed.
2. **Process Each Character**:
   - Build segments by accumulating characters until a dot is found.
   - Check if each segment is valid (correct range and no leading zeros).
   - Count dots to ensure there are exactly three.
3. **Final Check**: Verify that the last segment is also valid and that exactly three dots were found.

### Code

Here's the code with simplified explanations:

```cpp
class Solution {
  public:
    int isValid(string str) {
        int dots = 0;  // Counter for dots in the string
        string num = "";  // To build each segment
        
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '.') {
                // When we find a dot, validate the current segment
                if (num.empty() || num.size() > 3 || stoi(num) > 255 || (num.size() > 1 && num[0] == '0')) {
                    return false;  // Invalid segment found
                }
                num = "";  // Reset for the next segment
                dots++;  // Increase dot count
            } else {
                // Append digit to the current segment
                num += str[i];
            }
        }
        
        // Validate the last segment after the loop
        if (num.empty() || num.size() > 3 || stoi(num) > 255 || (num.size() > 1 && num[0] == '0')) {
            return false;  // Invalid last segment
        }
        
        // Check if there are exactly 3 dots
        return dots == 3;
    }
};
```

### Dry Run Example

**Input**: `str = "222.111.111.111"`

1. **Initialization**:
   - `dots = 0`
   - `num = ""`

2. **Processing**:
   - Read '2': `num = "2"`
   - Read '2': `num = "22"`
   - Read '2': `num = "222"`
   - Read '.': 
     - Check `num` (which is "222"): Valid (within range and no leading zero).
     - Reset `num` and increase `dots` to 1.
   - Continue similarly for the next segments.

3. **Final Check**:
   - Last segment "111" is also valid.
   - Total `dots = 3`, so it is valid.

### Complexity Analysis

- **Time Complexity**: O(n) where `n` is the length of the string. We go through the string once.
- **Space Complexity**: O(1). Only a few variables are used, and no extra space grows with input size.

This solution ensures that the IPv4 address is valid according to the rules, processing each part of the address efficiently.
