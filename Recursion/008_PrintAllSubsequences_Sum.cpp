/*
Given a number as integer s, find the sum of all the elements present in all possible subsequences of s.

Example 1:

Input:  S = "123" 
Output: 24
Explanation: {1}, {2}, {3}, {1, 2}, {2, 3}
{1, 3}, {1, 2, 3} are all possible sub-
sequences


  */




class Solution{
public:	

	// Recursive function to calculate the sum of all possible subsequences
    void generateSubsequences(string s, int index, string &temp, long long &sum) {
        if (index == s.length()) {
              if (!temp.empty()) {
                int num = stoi(temp);  // Convert string to integer
                while (num > 0) {
                    sum += num % 10;  // Add the last digit to the sum
                    num /= 10;  // Remove the last digit
                }
            }
            return;
        }

        // Include the current character
        temp += s[index];
        generateSubsequences(s, index + 1, temp, sum);

        // Exclude the current character
        temp.pop_back();
        generateSubsequences(s, index + 1, temp, sum);
    }

    int subsequenceSum(string s) {
        string temp = "";
        long long sum = 0;

        generateSubsequences(s, 0, temp, sum);

        // The sum can be a very large number, so it's better to return it as a long long
        return static_cast<int>(sum % 1000000007);  // Modulo operation to keep the result within bounds if needed
    }

};
