// A beautiful matrix is a matrix in which the sum of elements in each row and column is equal. 
//   Given a square matrix of size NxN. Find the minimum number of operation(s) that are required
// to make the matrix beautiful. In one operation you can increment the value of any one cell by 1.
// Example 1:

// Input:
// N = 2
// matrix[][] = {{1, 2},
//               {3, 4}}
// Output: 
// 4
// Explanation:
// Updated matrix:
// 4 3
// 3 4
// 1. Increment value of cell(0, 0) by 3
// 2. Increment value of cell(0, 1) by 1
// Hence total 4 operation are required.





// Function to find the minimum number of operations required
// to make the matrix beautiful.
int findMinOpeartion(vector<vector<int>> matrix, int n)
{
    // Create a vector to store the sum of elements in each row.
    vector<int> values(n);
    
    // Initialize a variable to keep track of the maximum sum needed.
    int need = 0;
    
    // Loop through each row and column of the matrix.
    for(int i = 0; i < n; i++){
        // Initialize variables to store the sum of the current row and column.
        int row, col;
        row = col = 0;
        
        // Calculate the sum of elements in the current row and column.
        for(int j = 0; j < n; j++){
            row += matrix[j][i]; // Sum of elements in the current column.
            col += matrix[i][j]; // Sum of elements in the current row.
        }
        
        // Update 'need' with the maximum of its current value, 'row', and 'col'.
        // This ensures 'need' keeps track of the maximum sum required to make
        // the matrix beautiful.
        need = max({need, row, col});
        
        // Store the sum of elements in the current row in the 'values' vector
        // for later use.
        values[i] = row;
    }
    
    // Initialize a variable to keep track of the total number of operations needed.
    int ans = 0;
    
    // Loop through each value in the 'values' vector (i.e., the sums of the rows).
    for(auto i : values)
        // For each value 'i', calculate the difference between 'need'
        // (the maximum required sum) and 'i' (the sum of the current row).
        // This difference represents the number of operations needed to make
        // the current row beautiful. Add this to 'ans' to accumulate the
        // total number of operations needed for all rows.
        ans += need - i;
        
    // Return the total number of operations required to make the entire matrix beautiful.
    return ans;
}
