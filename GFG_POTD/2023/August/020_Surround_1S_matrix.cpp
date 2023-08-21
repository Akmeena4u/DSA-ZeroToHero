// Given a matrix of order nxm, composed of only 0's and 1's, find the number of 1's in the matrix that are surrounded
//   by an even number (>0) of 0's. The surrounding of a cell in the matrix is defined as the elements above, 
//   below, on left, on right as well as the 4 diagonal elements around the cell of the matrix. Hence, 
//   the surrounding of any matrix elements is composed of 8 elements. Find the number of such 1's.


int Count(vector<vector<int> >& matrix) {
        // Code here
          int dx[] = { -1 , 1 ,  0  , 0 , -1  , -1  ,  1  , 1  };
        int dy[] = { 0  , 0 , -1  , 1 , -1  ,  1  , -1  , 1  };
        
        int ans = 0;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        auto valid = [&](int x, int y) -> bool {
            if(x < 0 or x >= n or y < 0 or y >= m)
                return 0;
                
            return matrix[x][y] == 0;
        };
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j]){
                    int cur = 0;
                    for(int k = 0; k < 8; k++){
                        int x = i + dx[k];
                        int y = j + dy[k];
                        
                        cur += valid(x, y);
                    }
                    
                    if(cur)
                        ans += !(cur & 1);
                }
            }
        }
        
        return ans;
    }
