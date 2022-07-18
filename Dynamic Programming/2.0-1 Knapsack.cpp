/*You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively.
Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of
this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or dont pick it (0-1 property).

Example 1:

Input:
N = 3
W = 4
values[] = {1,2,3}
weight[] = {4,5,1}
Output: 3
*/

//Recursive
int knapSack(int W, int wt[], int val[], int n)
{

    // Base Case
    if (n == 0 || W == 0)
        return 0;

    // If weight of the nth item is more
    // than Knapsack capacity W, then
    // this item cannot be included
    // in the optimal solution
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);

    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
        return max(
            val[n - 1]
                + knapSack(W - wt[n - 1], 
                           wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}

//T.c-pow(2,n)
//Auxiliary Space :O(1) + O(N). 
//As no extra data structure has been used for storing values but O(N) auxiliary stack space(ASS) has been used for recursion stack.

------------------------------------------------------------------------------------------------------------------
  
  //Memoisation
 
  
  
  --------------------------------------------------------------------------------
  Tabulation
   int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       int t[n+1][W+1];
       int i;
       int j;
       for(i=0;i<n+1;i++){
           for(j=0;j<W+1;j++){
               if(i==0 || j==0)
                t[i][j]=0;
           }
           
       }
       
       for(i=1;i<n+1;i++){
           for(j=1;j<W+1;j++){
               if(wt[i-1]<=j)
                t[i][j]= max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
       
       
                else if(wt[i-1]>j)
                t[i][j]=t[i-1][j];
           }
       }
       
       
       return t[n][W];
      
    }
    
};

Time Complexity: O(N*W). 
where 'N' is the number of weight element and 'W' is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
Auxiliary Space: O(N*W). 
The use of 2-D array of size 'N*W'.
  
=-------------------------------------------------------------------
  //more space optimised approach
  
