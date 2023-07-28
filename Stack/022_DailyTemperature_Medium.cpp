/*   Given an array of integers temperatures represents the daily temperatures, return an array answer such that
answer[i] is the number of days you have to wait after the ith day to get a warmer temperature.
If there is no future day for which this is possible, keep answer[i] == 0 instead.

   Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
  */


vector<int> dailyTemperatures(vector<int>& temperatures) {
         int n = temperatures.size();
        stack<int> st;
        
        vector<int> result(n);
        
        for(int i = n-1; i>=0; i--) {
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop();
            }
            
            if(st.empty()) {
                result[i] = 0;
            } else {
                result[i] = st.top() - i; //days
            }
            
            st.push(i);
        }
        
        return result;
    }
