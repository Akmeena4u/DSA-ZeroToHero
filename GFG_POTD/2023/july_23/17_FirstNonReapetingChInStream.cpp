/*

   Example 1:

Input: A = "aabc"
Output: "a#bb"
Explanation: For every ith character we will
consider the string from index 0 till index i first non
repeating character is as follow-
"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - there are two non repeating characters 'b' and 'c', 
first non-repeating character is 'b' because 'b' comes before
'c' in the stream.

  */

string FirstNonRepeating(string A){
		   
		    // Code here
		    int freq[26] = {0};
       queue<char> q;

  string ans = "";

  for(int i=0; i<A.length(); i++) {
          char ch = A[i];

          //increment frequency
          freq[ch - 'a']++;
          //q.push
          q.push(ch);

        while(!q.empty()) {
                if(freq[q.front() - 'a'] > 1) {
                        q.pop();
                }
                else {
                        ans.push_back(q.front());
                        break;
                }
        }

        if(q.empty()){
                ans.push_back('#');
        }
  }
 // cout << "Final Ans: " << ans << endl;
  return ans;
		}
		
