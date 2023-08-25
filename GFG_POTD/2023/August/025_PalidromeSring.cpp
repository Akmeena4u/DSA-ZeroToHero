class Solution{
public:	
	
	
	int isPalindrome(string S)
	{
	    // Your code goes here
	     int n = S.size();
     for(int i=0;i<n/2;i++)
	    if(S[i]!=S[n-1-i])return 0;
     return 1;
	}

};
