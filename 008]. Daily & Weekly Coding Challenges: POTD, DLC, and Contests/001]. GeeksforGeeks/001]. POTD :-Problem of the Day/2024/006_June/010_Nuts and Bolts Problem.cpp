/*### Problem Statement
You are given two arrays, `nuts` and `bolts`, each containing `n` elements. Both arrays contain the same elements but in different orders. Your task is to match the nuts and bolts such that each nut corresponds to a bolt and follows a specific order defined by a predefined character set `{'!', '#', '$', '%', '&', '*', '?', '@', '^'}`.

### Objective
Rearrange the `nuts` and `bolts` arrays such that:
1. Each element in the `nuts` array matches the corresponding element in the `bolts` array.
2. The elements are arranged in the predefined order mentioned above.

### Approach

1. Define the Character Order:
   We define a character array `charr` containing the order `{'!', '#', '$', '%', '&', '*', '?', '@', '^'}`.

2. Iterate Over the Order and Match:
   - We iterate over the predefined character order.
   - For each character in the predefined order, we iterate over the `nuts` and `bolts` arrays.
   - If the character matches an element in `nuts`, we add it to a `nut` vector.
   - Similarly, if the character matches an element in `bolts`, we add it to a `bolt` vector.

3. Reconstruct the Nuts and Bolts Arrays:
   - We reconstruct the original `nuts` and `bolts` arrays using the `nut` and `bolt` vectors which now contain the elements in the required order.

### Code  */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void matchPairs(int n, char nuts[], char bolts[]) {
        // Predefined order of characters
        char charr[] = {'!', '#', '$', '%', '&', '*', '?', '@', '^'};
        
        // Vectors to store matched nuts and bolts in the predefined order
        vector<char> nut;
        vector<char> bolt;
        
        // Matching and storing nuts and bolts in order
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < n; j++) {
                if (charr[i] == nuts[j]) {
                    nut.push_back(nuts[j]);
                }
                if (charr[i] == bolts[j]) {
                    bolt.push_back(bolts[j]);
                }
            }
        }
        
        // Reconstructing the original nuts and bolts arrays
        for (int i = 0; i < n; i++) {
            nuts[i] = nut[i];
            bolts[i] = bolt[i];
        }
    }
};

int main() {
    Solution solution;
    
    int n = 6;
    char nuts[] = {'@', '#', '$', '%', '^', '&'};
    char bolts[] = {'$', '%', '&', '^', '@', '#'};
    
    cout << "Original nuts: ";
    for (int i = 0; i < n; ++i) cout << nuts[i] << " ";
    cout << endl;

    cout << "Original bolts: ";
    for (int i = 0; i < n; ++i) cout << bolts[i] << " ";
    cout << endl;

    solution.matchPairs(n, nuts, bolts);

    cout << "Matched nuts:  ";
    for (int i = 0; i < n; ++i) cout << nuts[i] << " ";
    cout << endl;

    cout << "Matched bolts: ";
    for (int i = 0; i < n; ++i) cout << bolts[i] << " ";
    cout << endl;

    return 0;
}

/*
### Explanation

1. Character Order Definition:
   We define the character order array `charr` containing the predefined order of characters.

2. Vectors for Matched Elements:
   We initialize two vectors, `nut` and `bolt`, to store the matched elements from `nuts` and `bolts` respectively.

3. Matching Elements:
   - We iterate over the `charr` array to ensure we check each character in the predefined order.
   - For each character in `charr`, we iterate over the `nuts` and `bolts` arrays.
   - If the character in `charr` matches an element in `nuts`, we add it to the `nut` vector.
   - If the character in `charr` matches an element in `bolts`, we add it to the `bolt` vector.

4. Reconstructing Arrays:
   - After the matching process, we update the original `nuts` and `bolts` arrays with the elements from the `nut` and `bolt` vectors.

### Complexity Analysis

1. Time Complexity:
   - The outer loop runs for 9 iterations (fixed size of the character order array).
   - The inner loops run for `n` iterations.
   - Therefore, the overall time complexity is  O(9n), which simplifies to O(n) since 9 is a constant.

2. Space Complexity:
   - We use two additional vectors (`nut` and `bolt`), each of size `n`.
   - Therefore, the space complexity is O(n).

*/
