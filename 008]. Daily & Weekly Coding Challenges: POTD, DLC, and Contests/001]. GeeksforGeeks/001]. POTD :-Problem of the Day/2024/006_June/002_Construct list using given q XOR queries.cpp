/*
Problem Description: Construct list using given q XOR queries
- Given a list of queries, where each query is represented as a pair of integers (0 or 1, and X).
- If the first integer is 0, add X to the existing list.
- If the first integer is 1, perform a bitwise XOR operation on X with all elements in the list.

Solution Approach:
1. Brute Force Approach (Complexity: O(N^2)):
   - Initialize a list and start traversing through each query.
   - If the first integer is 0, add X to the list.
   - If the first integer is 1, perform XOR with X on all elements in the list.
   - Repeat for each query, and return the sorted list.

2. Optimized Approach (Complexity: O(N)):
   - Initialize a variable X as 0 (initial XOR value).
   - Traverse the queries from right to left.
   - If the first integer is 0, XOR X with the second integer and add it to the list.
   - If the first integer is 1, update X by XORing with the second integer.
   - At the end, sort and return the list.

*/

// Code Implementation (Optimized Approach):


vector<int> constructList(vector<vector<int>>& queries) {
    vector<int> answer;
    int X = 0;

    for (int i = queries.size() - 1; i >= 0; i--) {
        if (queries[i][0] == 0) {
            answer.push_back(queries[i][1] ^ X);
        } else {
            X ^= queries[i][1];
        }
    }
    answer.push_back(0^X);    // because initially list has one zero
    sort(answer.begin(), answer.end());
    return answer;
}


/* 
Algorithm Notes:
- The optimized approach reduces the time complexity to O(N) by traversing queries from right to left and updating the XOR value.
- It uses Two Main XOR properties - Identity and  Commutative 
- XOR Identity: Anything XORed with 0 equals itself. (A XOR 0 = A)
- Commutative and Associative: XOR operations are commutative and associative, so the order of XOR operations doesn't affect the result. (A XOR B = B XOR A, and (A XOR B) XOR C = A XOR (B XOR C))
- The code uses bitwise XOR (^) and STL sort for efficient implementation.


*/
