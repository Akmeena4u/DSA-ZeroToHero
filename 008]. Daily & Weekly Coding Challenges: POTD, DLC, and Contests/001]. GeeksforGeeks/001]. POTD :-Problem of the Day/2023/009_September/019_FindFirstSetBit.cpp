// Given an integer N. The task is to return the position of first set bit found from the right side in the binary representation of the number.
// Note: If there is no set bit in the integer N, then return 0 from the function.  

// Example 1:

// Input: 
// N = 18
// Output: 
// 2
// Explanation: 
// Binary representation of 18 is 010010,the first set bit from the right side is at position 2.





class Solution
{
    public:
    //Function to find position of first set bit in the given number.
  
  
        unsigned int getFirstSetBit(int n){
    // Initialize a variable to keep track of the position of the set bit.
    int pos = 1;

    // Iterate through each bit of the integer n.
    while (n > 0)
    {
        // Check if the least significant bit (rightmost bit) is set (1).
        if (n % 2 == 1)
            return pos;  // If set, return the current position.

        // If the least significant bit is not set, move to the next bit by dividing n by 2.
        n /= 2;

        // Increment the position to move to the next bit.
        pos++;
    }

    // If no set bit was found, return 0 to indicate that there are no set bits.
    return 0;
}

    
};
