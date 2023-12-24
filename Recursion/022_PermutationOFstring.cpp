/*
Given a string S. The task is to print all unique permutations of the given string in lexicographically sorted order.

Example 1:

Input: ABC
Output:
ABC ACB BAC BCA CAB CBA
Explanation:
Given string ABC has permutations in 6 
forms as ABC, ACB, BAC, BCA, CAB and CBA .


  */


void permutate(string &S , vector<string>&ans , int s){
            if(s>=S.size()){
                ans.push_back(S);
                return;
            }
            unordered_set<char>st;
            for(int i=s;i<S.size();i++){
                if(st.find(S[i])!= st.end()) continue ;
                st.insert(S[i]);
                swap(S[i],S[s]);
                permutate(S,ans,s+1);
                swap(S[i],S[s]);
            }
        }
        vector<string>find_permutation(string S)
        {
           vector<string>ans;
           permutate(S,ans,0);
           sort(ans.begin(),ans.end());
           return ans;
        }
