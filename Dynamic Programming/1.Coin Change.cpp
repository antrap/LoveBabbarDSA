Coin Change

s={1,2,3....} find change for m

//Recursive Approach
int count(int S[], int m, int n)
{
    
    // If n is 0 then there is 1 solution 
    // (do not include any coin)
    if (n == 0)
        return 1;
    
    // If n is less than 0 then no 
    // solution exists
    if (n < 0)
        return 0;

    // If there are no coins and n 
    // is greater than 0, then no
    // solution exist
    if (m <= 0 && n >= 1)
        return 0;

    // count is sum of solutions (i) 
    // including S[m-1] (ii) excluding S[m-1]
    return count(S, m - 1, n) + 
           count(S, m, n - S[m - 1]);
}
Time Complexity: O(pow(2,n))

Space Complexity: O(target) - Auxiliary stack space

------------------------------------------------------------------------------------------------
//Memoisation
int coinchange(vector<int>& a, int v, int n,
               vector<vector<int> >& dp)
{
    if (v == 0)
        return dp[n][v] = 1;
    if (n == 0)
        return 0;
    if (dp[n][v] != -1)
        return dp[n][v];
    if (a[n - 1] <= v) {
        // Either Pick this coin or not
        return dp[n][v] = coinchange(a, v - a[n - 1], n, dp)
                          + coinchange(a, v, n - 1, dp);
    }
    else // We have no option but to leave this coin
        return dp[n][v] = coinchange(a, v, n - 1, dp);
}
vector<vector<int> > dp(n + 1,
                                vector<int>(v + 1, -1));

Time Complexity: O(M*N)
Auxiliary Space: O(M*N)
  
------------------------------------------------------------------------------------------------------
 //Tabulation
  long long int count(int S[], int m, int n) {

        // code here.
        
        long long int dp[n+1][m+1];
        
        for(long long int i=0;i<=m;i++){
            dp[0][i]=1;
        }
        
        for(long long int i=1;i<=n;i++){
            dp[i][0]=0;
        }
        
        
        for(long long int i=1;i<=n;i++){
            for(long long int j=1;j<=m;j++){
                dp[i][j]=dp[i][j-1];
                
                if(S[j-1]<=i)
                dp[i][j]+=dp[i-S[j-1]][j];
            }
        }
        
        return dp[n][m];
    }
