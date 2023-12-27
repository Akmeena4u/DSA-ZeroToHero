// Function to extract the anti-diagonal pattern from a given matrix
vector<int> antiDiagonalPattern(vector<vector<int>>& matrix) {
    int num_rows = matrix.size();
    int num_cols = matrix[0].size();

    // Dictionary to store elements grouped by their anti-diagonal index
    unordered_map<int, vector<int>> anti_diagonal_groups;

    // Populate anti_diagonal_groups dictionary
    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            int anti_diagonal_index = i + j;
            anti_diagonal_groups[anti_diagonal_index].push_back(matrix[i][j]);
        }
    }

    vector<int> result;

    // Flatten the anti-diagonal groups into the final result list
    for (int i = 0; i < num_rows + num_cols - 1; ++i) {
        result.insert(result.end(), anti_diagonal_groups[i].begin(), anti_diagonal_groups[i].end());
    }

    return result;
}

// An anti-diagonal matrix is a matrix where all the elements are on a diagonal
// that runs from the top right to the bottom left of the matrix.
// For example, in a 3x3 matrix:
// 1 2 3
// 4 5 6
// 7 8 9
// The anti-diagonal elements are: 3, 6, 9.