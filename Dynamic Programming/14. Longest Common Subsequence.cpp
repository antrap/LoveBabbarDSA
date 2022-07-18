//LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them. 
//A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.
//For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”. 


//Recursion
int lcs( char *X, char *Y, int m, int n )
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m-1] == Y[n-1])
        return 1 + lcs(X, Y, m-1, n-1);
    else
        return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}
 //Time complexity of the above naive recursive approach is O(2^n) in worst case 

----------------------------------------------------------------------------------------
//Memoisation
int lcs(char* X, char* Y, int m, int n,
        vector<vector<int> >& dp)
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1, dp);
 
    if (dp[m][n] != -1) {
        return dp[m][n];
    }
    return dp[m][n] = max(lcs(X, Y, m, n - 1, dp),
                          lcs(X, Y, m - 1, n, dp));
}
//Time Complexity : O(mn) ignoring recursion stack space


--------------------------------------------------------------------------------------
  //Tabulation
  int lcs(char *X, char *Y, int m, int n)
{
    // intitalizing a matrix of size (m+1)*(n+1)
    int L[m + 1][n + 1];
 
    /* Following steps build L[m+1][n+1] in bottom up fashion. Note
        that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
 
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
 
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
 
    // L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1]
    return L[m][n];
}
//Time Complexity of the above implementation is O(mn)
