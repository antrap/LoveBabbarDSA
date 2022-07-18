Given a rod of length L, the task is to cut the rod in such a way that the total number of segments of length p, q and r is maximized. The segments can only be of length p, q, and r. 

Examples: 

Input: l = 11, p = 2, q = 3, r = 5 
Output: 5 
Segments of 2, 2, 2, 2 and 3
  
  
 //Memoisation
  int func(int l, int p, int q, int r)
{
    if(l==0)
       return 0;                               // Base Case
            
     if(dp[l]!=-1)                              // If already memoized
        return dp[l];
         
     int a(INT_MIN),b(INT_MIN),c(INT_MIN);         // Intitialise a,b,& c with INT_MIN
   
     if(p<=l)                                      // If Possible to make a cut of length p
        a=func(l-p,p,q,r);
   
     if(q<=l)                                      // If possible to make a cut of length q
        b=func(l-q,p,q,r);
   
     if(r<=l)                                      // If possible to make a cut of length r
        c=func(l-r,p,q,r);
   
     return dp[l]=1+max({a,b,c});                    // Memoize & return
         
}
Time Complexity : O(n) where n is the length of rod or line segment that has to be cut.

Space Complexity : O(n) where n is the length of rod or line segment that has to be cut


------------------------------------------------------------------------------------------------
int findMaximum(int l, int p, int q, int r)
{
 
    // Array to store the cut at each length
    int dp[l + 1];
 
    // All values with -1
    memset(dp, -1, sizeof(dp));
 
    // if length of rod is 0 then total cuts will be 0
    // so, initialize the dp[0] with 0
    dp[0] = 0;
 
    for (int i = 0; i <= l; i++) {
 
        // if certain length is not possible
        if (dp[i] == -1)
            continue;
 
        // if a segment of p is possible
        if (i + p <= l)
            dp[i + p] = max(dp[i + p], dp[i] + 1);
 
        // if a segment of q is possible
        if (i + q <= l)
            dp[i + q] = max(dp[i + q], dp[i] + 1);
 
        // if a segment of r is possible
        if (i + r <= l)
            dp[i + r] = max(dp[i + r], dp[i] + 1);
    }
    // if no segment can be cut then return 0
    if (dp[l] == -1) {
        dp[l] = 0;
    }
    // return value corresponding to length l
    return dp[l];
}
 o(N)
