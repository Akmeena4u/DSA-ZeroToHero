class Solution{
    public:
    // Function to check if given number n is a power of two.
    
    int check(long long n){
         // A power of two in binary has only one '1' bit set.
        // Using the bitwise 'AND' operator with (number - 1) will result in 0 for powers of two.
        return (n != 0) && ((n & (n - 1)) == 0);
    }
    
    bool isPowerofTwo(long long n){
        
        if (check(n))  return true; 
        else     return false;
        
    }
};
