/*
Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int count = 0;
        while(n!=0) {
            
            //checking last bit
            if(n&1) {
                count++;
            }
            n = n>>1;
        }
        return count;
    }
};
