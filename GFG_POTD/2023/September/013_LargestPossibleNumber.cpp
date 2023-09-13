// Given two numbers 'N' and 'S' , find the largest number that can be formed with 'N' digits and whose sum of digits should be equals to 'S'. Return -1 if it is not possible.

// Example 1:

// Input: N = 2, S = 9
// Output: 90
// Explaination: It is the biggest number 
// with sum of digits equals to 9.



class Solution{
public:
    string findLargest(int n, int S){
        // code here
        string ans = "";
        if (S == 0 && n > 1)
            return "-1";
        for (int i = 0; i < n; i++) {
            if (S >= 9) {
                ans += '9';
                S -= 9;
            } else {
                ans += (char)(S + 48);
                S = 0;
            }
        }
        if (S > 0) // eg N=2, S=20
            return "-1";
    
        return ans;
    }
};
