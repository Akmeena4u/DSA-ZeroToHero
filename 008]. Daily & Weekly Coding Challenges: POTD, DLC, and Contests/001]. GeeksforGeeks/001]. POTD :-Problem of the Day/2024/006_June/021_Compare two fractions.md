### Comparing Two Fractions

**Problem Statement:**
- Given two fractions, `a/b` and `c/d`, where `a`, `b`, `c`, and `d` are integers.
- The task is to compare these two fractions and return:
  - "equal" if the fractions are equal.
  - The larger fraction in string format if they are not equal.

**Input Representation:**
- The input is a single string representing the two fractions separated by a comma and a space.
- Example: "10/5, 20/5" where `a/b` is `10/5` and `c/d` is `20/5`.

**Steps to Solve the Problem:**
1. **Parsing the Input String:**
   - Initialize variables to hold the values of `a`, `b`, `c`, and `d`.
   - Iterate through the string to extract these values.
   - Split the input string based on the '/' and ',' characters.

2. **Extracting Numerator and Denominator:**
   - Start with `i` at index 0 and parse until the '/' is encountered to get `a`.
   - Move past the '/' and continue parsing until the ',' is encountered to get `b`.
   - Skip the ", " and parse until the '/' is encountered to get `c`.
   - Move past the '/' and continue parsing until the end of the string to get `d`.

3. **Converting to Integer and Comparing Fractions:**
   - Convert the extracted parts into integers.
   - Compare the fractions by evaluating the conditions:
     - If `a/b` equals `c/d`, return "equal".
     - If `a/b` is greater than `c/d`, return `a/b` in string format.
     - Otherwise, return `c/d` in string format.

4. **Edge Case Handling:**
   - Ensure proper conversion to avoid floating-point inaccuracies by using integer arithmetic.

**Code Implementation:**

```cpp
class Solution {
public:
    string compareFrac(string s) {
        // Initialize variables
        int i = 0, n = s.length();
        double a = 0, b = 0, c = 0, d = 0;

        // Extract numerator of first fraction
        while (s[i] != '/') {
            a = a * 10 + (s[i] - '0');
            i++;
        }
        i++; // Move past '/'

        // Extract denominator of first fraction
        while (s[i] != ',') {
            b = b * 10 + (s[i] - '0');
            i++;
        }
        i += 2; // Move past ", "

        // Extract numerator of second fraction
        while (s[i] != '/') {
            c = c * 10 + (s[i] - '0');
            i++;
        }
        i++; // Move past '/'

        // Extract denominator of second fraction
        while (i < n) {
            d = d * 10 + (s[i] - '0');
            i++;
        }

        // Create string representations of the fractions
        string fraction1 = to_string(int(a)) + '/' + to_string(int(b));
        string fraction2 = to_string(int(c)) + '/' + to_string(int(d));

        // Compare the fractions
        if (a / b == c / d) return "equal";
        else if (a / b > c / d) return fraction1;
        else return fraction2;
    }
};
```

**Key Points to Remember:**
- The input string format and parsing are crucial.
- Proper handling of numerical conversion to avoid floating-point inaccuracies.
- Using integer arithmetic for comparison is reliable and avoids precision issues.
- Ensure the return values are in the correct string format as specified in the problem.
