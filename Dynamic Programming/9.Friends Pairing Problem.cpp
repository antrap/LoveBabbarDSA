Friends Pairing Problem
Given N friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.
Note: Since answer can be very large, return your answer mod 10^9+7.


Example 1:

Input:N = 3
Output: 4
Explanation:
{1}, {2}, {3} : All single
{1}, {2,3} : 2 and 3 paired but 1 is single.
{1,2}, {3} : 1 and 2 are paired but 3 is single.
{1,3}, {2} : 1 and 3 are paired but 2 is single.
Note that {1,2} and {2,1} are considered same.
  
  
 int countFriendsPairings(int n) 
    { 
        // code here
        long long int dp[n+1];
        for(int i=0;i<n+1;i++){
            if(i<=2)
            dp[i]=i;
            
            else dp[i]=(dp[i-1]%mod+((i-1)*dp[i-2])%mod)%mod;
        }
        
        
        return dp[n];
    }
