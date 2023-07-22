//brute

void rotate(int matrix[][3]) {
  int n = 3;

  //Creating new matrix to store rotated values
  int temp[n][n];

  int ind = n - 1;
  for (int i = 0; i < n; i++) {

    for (int j = 0; j < n; j++) {
      temp[i][j] = matrix[j][ind];
    }
    ind--;
  }


//better ---inplace rotation
void rotate(vector<vector<int> >& matrix)
{
    // Your code goes here
    /* Finding transpose*/
    int n=matrix.size();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }
  }
  
  // Reverse every column
for (int i = 0; i < n; i++) {
    int start = 0;
    int end = n - 1;
    while (start < end) {
        int temp = matrix[start][i];
        matrix[start][i] = matrix[end][i];
        matrix[end][i] = temp;
        start++;
        end--;
    }
}
// for(int i=0;i<n;i++){
//     reverse(matrix[i].begin(),matrix[i].end());
// }

}
