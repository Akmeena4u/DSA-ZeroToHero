// //
// Input: N = 43
// Output: 20 20 2 1
// Explaination: 
// Minimum number of coins and notes needed 
// to make 43. 

#include<bits/stdc++.h>


using namespace std;
int main() {
  int V = 49;
  vector < int > ans;
  int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
  int n = 9;
  for (int i = n - 1; i >= 0; i--) {
    while (V >= coins[i]) {
      V -= coins[i];
      ans.push_back(coins[i]);
    }
  }
  cout<<"The minimum number of coins is "<<ans.size()<<endl;
  cout<<"The coins are "<<endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}

//simpler
class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
           int coins[] = {2000,500,200,100,50,20,10,5,2,1};
       vector<int>ans;
       int rem = N ;
       for( int i =0 ; i < 10 ; i++){
           if( rem >= coins[i]){
               ans.push_back( coins[i]);
               rem = rem - coins[i];
               i--;
           }
       }
       return ans;
    }
};
