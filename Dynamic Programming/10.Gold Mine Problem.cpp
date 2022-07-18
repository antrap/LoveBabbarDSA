Given a gold mine of n*m dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner is at first column but can be at any row. He can move only (right->,right up /,right down\) that is from a given cell, the miner can move to the cell diagonally up towards the right or right or diagonally down towards the right. Find out maximum amount of gold he can collect. 
Examples: 
 

Input : mat[][] = {{1, 3, 3},
                   {2, 1, 4},
                  {0, 6, 4}};
Output : 12 
{(1,0)->(2,1)->(1,2)}


//Recursion
int collectGold(vector<vector<int>> gold, int x, int y, int n, int m) {
 
    // Base condition.
    if ((x < 0) || (x == n) || (y == m)) { 
        return 0;
    }
   
 
    // Right upper diagonal
    int rightUpperDiagonal = collectGold(gold, x - 1, y + 1, n, m);
 
     // right
    int right = collectGold(gold, x, y + 1, n, m);
 
    // Lower right diagonal
    int rightLowerDiagonal = collectGold(gold, x + 1, y + 1, n, m); 
 
    // Return the maximum and store the value
    return  gold[x][y] + max(max(rightUpperDiagonal, rightLowerDiagonal), right); 
}
 
int getMaxGold(vector<vector<int>> gold, int n, int m)
{
    int maxGold = 0;
 
    for (int i = 0; i < n; i++) {
 
        // Recursive function call for  ith row.
        int goldCollected = collectGold(gold, i, 0, n, m); 
        maxGold = max(maxGold, goldCollected);
    }
 
    return maxGold;
}

Time complexity: O(3N*M)

  Auxiliary Space: O(N*M)
    
    ------------------------------------------------------------------------------------------------------
    //Memoisation
    int collectGold(vector<vector<int>> gold, int x, int y, int n, int m, vector<vector<int>> &dp) {
 
    // Base condition.
    if ((x < 0) || (x == n) || (y == m)) { 
        return 0;
    }
   
    if(dp[x][y] != -1){
        return dp[x][y] ;
    }
 
    // Right upper diagonal
    int rightUpperDiagonal = collectGold(gold, x - 1, y + 1, n, m, dp);
 
     // right
    int right = collectGold(gold, x, y + 1, n, m, dp);
 
    // Lower right diagonal
    int rightLowerDiagonal = collectGold(gold, x + 1, y + 1, n, m, dp); 
 
    // Return the maximum and store the value
    return dp[x][y] = gold[x][y] + max(max(rightUpperDiagonal, rightLowerDiagonal), right); 
}
 
int getMaxGold(vector<vector<int>> gold, int n, int m)
{
    int maxGold = 0;
    // Initialize the dp vector
    vector<vector<int>> dp(n, vector<int>(m, -1)) ;
    for (int i = 0; i < n; i++) {
 
        // Recursive function call for  ith row.
        int goldCollected = collectGold(gold, i, 0, n, m, dp); 
        maxGold = max(maxGold, goldCollected);
    }
 
    return maxGold;
}
 Time Complexity :O(m*n)

Space Complexity :O(m*n)
  
  
  ---------------------------------------------------------------------------------
  
  //Tabulation
