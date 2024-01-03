//User function Template for C++


class Solution
{
    public:
    
     void solve(vector<string> &ans ,int index , int a[] ,int n, string output , vector<string> &mapping){

//base case
//int N = sizeof(a)/sizeof(int);
if(index==n){
    ans.push_back(output);
    return;
}


// 1 case solve kardo 

int digit= a[index];

string val= mapping[digit];

for(int i=0;i<val.length();i++){

    char ch = val[i];

    output.push_back(ch);

    solve(ans, index+1 , a ,n,output, mapping);

    //backtrack
    output.pop_back();
}






   }




    vector<string> letterCombinations(string digits) {
       
    }
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
         vector<string>ans;
        if(N==0){
             return ans;
        }

        int index=0;
        string output="";

        vector<string> mapping(10);

        mapping[2]="abc";
        mapping[3]="def";
        mapping[4]="ghi";
        mapping[5]="jkl";
        mapping[6]="mno";
        mapping[7]="pqrs";
        mapping[8]="tuv";
        mapping[9]="wxyz";

        solve(ans , index,a,N, output , mapping  );
        return ans;
    }
};