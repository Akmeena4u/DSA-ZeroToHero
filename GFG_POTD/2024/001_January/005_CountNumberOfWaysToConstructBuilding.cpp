/*



There is a road passing through a city with N plots on both sides of the road. Plots are arranged in a straight line on either side of the road. Determine the total number of ways to construct buildings in these plots, ensuring that no two buildings are adjacent to each other. Specifically, buildings on opposite sides of the road cannot be adjacent.

Using * to represent a plot and || for the road, the arrangement for N = 3 can be visualized as follows: * * * || * * *.

Note: As the answer can be very large, print it mod 109+7.

Example 1:

Input: N = 1
Output: 4
Explanation: 
Possible ways for the arrangement are B||*, *||B, B||B, *||*
where B represents a building.*/



class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	    
	   
         long bCount = 1 , sCount = 1;
         int mod=1000000007;
        
        for(int i = 2 ; i <= N ;i++){
            
            long newbCount = sCount;
            long newsCount = bCount%mod+sCount%mod;
            
            bCount =  newbCount;
            sCount =  newsCount;
        }
    
        long total = sCount+bCount;
        return (int)(total%mod*total%mod)%mod;
   
	}
};

