/*--kitni baar kya aaya h 
1- 
11 - 1 baar one ayaya h 
21- 2 baar one aaaya h 
1211-1 baar two aaya h and 1 bar one aaya h 


approch:--
Initialize the sequence with "11" and iterate from the third term up to the desired term n.
Use a delimiter ('$') to handle the last group of digits in the inner loop.
Update the string for each iteration to build the next term of the "Look and Say" sequence.
*/

class Solution
{
  public:
    string lookandsay(int n) {
        // code here
    if (n == 1) return "1";
    if (n == 2) return "11";

    string s = "11";

    for (int i = 3; i <= n; i++) {
        string t = "";
        s=s+'$';
        int c = 1;

        for (int j = 1; j < s.length(); j++) {
            if (s[j] != s[j - 1]) {
                t = t + to_string(c) + s[j - 1];
                c = 1;
            } 
            else {
                c++;
            }
        }

        s = t;
    } return s;  
    }
};
