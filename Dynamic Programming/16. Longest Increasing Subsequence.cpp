//The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a
//given sequence such that all elements of the subsequence are sorted in increasing order. 
//For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}. 


//Recursive
int _lis(int arr[], int n, int* max_ref)
{
    /* Base case */
    if (n == 1)
        return 1;
 
    // 'max_ending_here' is length of LIS
    // ending with arr[n-1]
    int res, max_ending_here = 1;
 
    /* Recursively get all LIS ending with arr[0],
    arr[1] ... arr[n-2]. If arr[i-1] is smaller
    than arr[n-1], and max ending with arr[n-1]
    needs to be updated, then update it */
    for (int i = 1; i < n; i++) {
        res = _lis(arr, i, max_ref);
        if (arr[i - 1] < arr[n - 1]
            && res + 1 > max_ending_here)
            max_ending_here = res + 1;
    }
 
    // Compare max_ending_here with the overall
    // max. And update the overall max if needed
    if (*max_ref < max_ending_here)
        *max_ref = max_ending_here;
 
    // Return length of LIS ending with arr[n-1]
    return max_ending_here;
}
 //Time Complexity: The time complexity of this recursive approach is exponential as there is a case of overlapping
//subproblems as explained in the recursive tree diagram above.
//Auxiliary Space: O(1). No external space used for storing values apart from the internal stack space.

-----------------------------------------------------------------------------------
