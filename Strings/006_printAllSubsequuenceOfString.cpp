/*
Given a string S, Find all the possible subsequences of the String in lexicographically-sorted order.

Example 1:

Input : str = "abc"
Output: a ab abc ac b bc c
Explanation : There are 7 subsequences that 
can be formed from abc.


approch- follow include-exclude pattern '

 "lexicographically-sorted order," it means arranging the elements of the sequence in the same order as they would appear in a dictionary (lexicon)

*/

class Solution{
	public:
		 void solve(string s,vector<string>&st,int ind,string &str){
		     
	      if(ind>=s.size())
	       {
	           return ;
	       }
	       for(int i=ind;i<s.size();i++)
	       {
	           str+=s[i];
	           solve(s,st,i+1,str);
	           st.push_back(str);
	           str.pop_back();
	       }
	  }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		  //  sort(s.begin(),s.end());
		    int i=0;
		    vector<string>st;
		    string str="";
		    solve(s,st,i,str);
		    sort(st.begin(),st.end());
		    return st;
		}
};
