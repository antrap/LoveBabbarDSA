//P(n, k) = P(n-1, k) + k* P(n-1, k-1)   




int permutationCoeff(int n, int k)
{
    int P[n + 1][k + 1];
  
    // Calculate value of Permutation
    // Coefficient in bottom up manner
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= std::min(i, k); j++)
        {
            // Base Cases
            if (j == 0)
                P[i][j] = 1;
  
            // Calculate value using
            // previously stored values
            else
                P[i][j] = P[i - 1][j] +
                        (j * P[i - 1][j - 1]);
  
            // This step is important
            // as P(i,j)=0 for j>i
            P[i][j + 1] = 0;
        }
    }
    return P[n][k];
}
//time complexity is O(n*k) and space complexity is O(n*k)


------------------------------------------------------------------------------
  
  int permutationCoeff(int n, int k)
{
    int fact[n + 1];
 
    // Base case
    fact[0] = 1;
 
    // Calculate value
    // factorials up to n
    for(int i = 1; i <= n; i++)
    fact[i] = i * fact[i - 1];
 
    // P(n,k) = n! / (n - k)!
    return fact[n] / fact[n - k];
}
//O(n) time
//O(n)space 

------------------------------------------------------------------------------------------------------------
  A O(n) time and O(1) Extra Space Solution 
  int PermutationCoeff(int n, int k)
{
    int P = 1;
 
    // Compute n*(n-1)*(n-2)....(n-k+1)
    for (int i = 0; i < k; i++)
        P *= (n-i) ;
 
    return P;
}
