//A binomial coefficient C(n, k) can be defined as the coefficient of x^k in the expansion of (1 + x)^n.
//C(n, k) = C(n-1, k-1) + C(n-1, k)
   C(n, 0) = C(n, n) = 1
     
 //Recursive Approach
 int binomialCoeff(int n, int k)
{
    // Base Cases
    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;
 
    // Recur
    return binomialCoeff(n - 1, k - 1)
           + binomialCoeff(n - 1, k);
}

//Time Complexity: O(n*max(k,n-k)) 

//Auxiliary Space: O(n*max(k,n-k))


------------------------------------------------------------------------------------------------
  //Tabulation Approach
  int nCr(int n, int r){
        // code here
        if(r>n)  return 0;
        int dp[n+1][r+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<=min(i,r);j++){
                
                if(j==0 || j==i)
                dp[i][j]=1;
                
                else dp[i][j]=(dp[i-1][j-1]%mod+dp[i-1][j]%mod)%mod;
            }
        }
        
        return dp[n][r]%mod;
    }

//Time Complexity: O(n*k) 
//Auxiliary Space: O(n*k)
