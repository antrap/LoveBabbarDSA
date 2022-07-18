//Given an array A[] of size N, find the longest subsequence such that difference between adjacent elements is one.


Example 1:

Input: N = 7
A[] = {10, 9, 4, 5, 4, 8, 6}
Output: 3
Explaination: The three possible subsequences 
{10, 9, 8} , {4, 5, 4} and {4, 5, 6}.
  
  
  int longestSubsequence(int N, int A[])
    {
        // code here
        int ldiffs[N];
        for(int i=0;i<N;i++){
            ldiffs[i]=1;
        }
        
        for(int i=1;i<N;i++){
            for(int j=0;j<i;j++){
                if((A[i]==A[j]+1) || (A[i]==A[j]-1))
                ldiffs[i]=max(ldiffs[i],ldiffs[j]+1);
            }
        }
        
        int res=0;
        for(int i=0;i<N;i++){
            res=max(res,ldiffs[i]);
        }
        
        return res;
    }
