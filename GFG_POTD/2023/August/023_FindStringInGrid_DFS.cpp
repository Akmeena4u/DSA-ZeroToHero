// Given a 2D grid of n*m of characters and a word, find all occurrences of given word in grid.
//   A word can be matched in all 8 directions at any point. Word is said to be found in a direction
// if all characters match in this direction (not in zig-zag form). The 8 directions are, horizontally left,
//   horizontally right, vertically up, vertically down, and 4 diagonal directions.


class Solution {
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	       int dx[] = { -1 , 1 ,  0  , 0 , -1  , -1  ,  1  , 1  };
        int dy[] = { 0  , 0 , -1  , 1 , -1  ,  1  , -1  , 1  };
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> ans;
        
        auto valid = [&](int x, int y, int p) -> bool {
            if(x < 0 or x >= n or y < 0 or y >= m)
                return 0;
            
            return grid[x][y] == word[p];
        };
        
        function<bool(int, int, int, int)> helper = [&](int x, int y, int dir, int p) -> bool {
            if(p == word.size() - 1)
                return 1;
                
            if(valid(x + dx[dir], y + dy[dir], p + 1))
                return helper(x + dx[dir], y + dy[dir], dir, p + 1);
                
            return 0;
        };
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < 8; k++){
                    if(valid(i, j, 0) and helper(i, j, k, 0)){
                        vector<int> t = {i, j};
                        ans.push_back(t);
                        break;
                    }
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
	}
	
};
