/*   Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "1 + 1"
Output: 2

  */


int calculate(string s) {
         stack<int> st;
        int number = 0;
        int result = 0;
        int sign   = 1;
        
        for(int i = 0; i<s.length(); i++) {
            if(isdigit(s[i])) {
                //number banao
                number  = 10*number + (s[i] - '0');
            } else if(s[i] == '+') {
                //number already ban chuka h 
                //add into result and make number =0  ,,,, sign=+1;
                result += sign*number;
                number  = 0;
                sign = 1; //For further
            } else if(s[i] == '-') {
                result += sign*number;
                number  = 0;
                sign = -1; //For further
            } else if(s[i] == '(') {
                //phale wale result ko stack me push kardo and uske baad sign ko bhi push kardo
                //or ab new bracket ko solve karna h so result and number ko zero kardo and sign=1
                st.push(result);
                st.push(sign);
                result = 0;
                number = 0;
                sign = 1;
            } else if(s[i] == ')') {
                //ab tk ek bracket pura solve ho chuka h to ab ise previos result me add karna h
                //result banoo bracket ka
                //stack ke top pe jo sign h usase multiply karo
                //add karo stack ka top
                result += sign*number;
                number = 0;
                int top = st.top(); st.pop();
                result *= top;
                top = st.top(); st.pop();
                result += top;
            }
        }
        result += (sign*number);
        return result;
    }
