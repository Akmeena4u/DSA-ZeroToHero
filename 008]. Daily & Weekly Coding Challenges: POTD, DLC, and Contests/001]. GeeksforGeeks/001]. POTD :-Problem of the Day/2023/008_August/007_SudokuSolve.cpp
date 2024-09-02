class Solution 
{
    public:
    
    bool isSafe(int row, int col, int grid[N][N], char value) {
        

     for(int i=0; i<N; i++) {
            //row check
            if(grid[row][i] == value)
                return false;
            
            //col check
            if(grid[i][col] == value) 
                return false;

            //3*3 box check
            if(grid[3*(row/3)+(i/3)][3*(col/3)+(i%3)] == value) 
                return false;
        }

        return true;
    }


    //Function to find a solved Sudoku. 
    bool Solve(int grid[N][N])  
    { 
        // Your code herE
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                //check for empty cell
                if(grid[i][j] == 0) {
                    //try to fill with values ranging from 1 to 9
                    for(int val = 1; val<=9; val++) {
                        //check for safety
                        if(isSafe(i,j, grid, val)) {
                            //insert
                            grid[i][j] = val;
                            //recursion sambal lega
                            bool remainingBoardSolution = Solve( grid);
                            if(remainingBoardSolution == true) {
                                return true;
                            }
                            else {
                                //backtrack
                                grid[i][j] = 0;
                            }
                        }
                    }
                
                return false;
                }
            }
        }
        //all cells filled 
        return true;
    }
    

    bool SolveSudoku(int grid[N][N]){
        Solve(grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
    
        for(int i=0;i<N;i++){
            
            for(int j=0 ;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
        }
        
    }
    
};
