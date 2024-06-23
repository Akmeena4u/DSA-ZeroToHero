### Print Bracket Numbers Problem

#### Problem Description
Given a string `str`, the task is to find the bracket numbers. For each bracket in the string, we need to return the sequence number of the brackets.

#### Example:
1. Input: `str = "(())()"`
   Output: `1 2 2 1 3 3`
2. Input: `str = "(((())))"`
   Output: `1 2 3 4 4 3 2 1`

#### Explanation:
For each opening bracket `(`, we assign a unique number incrementally. For each closing bracket `)`, we assign the number corresponding to the most recent unmatched opening bracket.

#### Approach:
1. Traverse through the string character by character.
2. Use a stack to keep track of the opening brackets and their corresponding numbers.
3. Use a counter to assign the bracket numbers incrementally.
4. For each opening bracket, push its number onto the stack.
5. For each closing bracket, pop the number from the stack.
6. Store the results in a list and print them.

#### Implementation

Below is the complete code, including the `Solution` class implementation for the `bracketNumbers` function, along with the driver code:

```cpp
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> bracketNumbers(string str) {
        vector<int> ans;
        stack<int> st;
        int opens = 0;
        for (auto it : str) {
            if (it == '(') {
                opens++;
                st.push(opens);
                ans.push_back(st.top());
            }
            else if (it == ')') {
                ans.push_back(st.top());
                st.pop();
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        vector<int> ans = ob.bracketNumbers(s);

        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends
```

### Breakdown of the Solution:
1. The `bracketNumbers` function takes a string of brackets and returns a vector of integers representing the numbering of each bracket.
2. The `opens` variable keeps track of the opening brackets' count.
3. A stack `st` is used to manage the numbering of the brackets.
4. When encountering an opening bracket `(`, the counter `opens` is incremented, the value is pushed onto the stack, and the value is added to the result vector.
5. When encountering a closing bracket `)`, the top value of the stack is added to the result vector, and the stack is popped.

### Driver Code:
The driver code reads the input, creates an instance of the `Solution` class, calls the `bracketNumbers` function, and prints the resulting vector for each test case.
