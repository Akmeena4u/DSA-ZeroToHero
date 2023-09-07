// Input:
// 5 3
// 1 2 3 4 5
// 1 2 3
// Output: 
// 5
// Explanation: 
// 1, 2, 3, 4 and 5 are the
// elements which comes in the union set
// of both arrays. So count is 5.


class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        //code here
         // Create a set to store the unique elements.
  set<int> s;

  // Add the elements of array a to the set.
  for (int i = 0; i < n; i++) {
    s.insert(a[i]);
  }

  // Add the elements of array b to the set.
  for (int i = 0; i < m; i++) {
    s.insert(b[i]);
  }

  // Return the number of elements in the set.
  return s.size();

    }
};
