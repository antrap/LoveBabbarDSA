int equalPartition(int N, int arr[])
    {
        // code here
        int sumarr=0;
        for(int i=0;i<N;i++){
            sumarr+=arr[i];
        }
        if(sumarr%2!=0)  return 0;
        
        int equalsum=sumarr/2;
        return isSubsetSum(arr,equalsum,N);
    }
    int isSubsetSum(int arr[],int sum,int n){
        int dp[n+1][sum+1];
        
        for(int i=0;i<n+1;i++){
            dp[i][0]=1;
        }
        
        for(int i=1;i<sum+1;i++){
            dp[0][i]=0;
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
                
                else dp[i][j]=dp[i-1][j];
            }
        }
        
        return dp[n][sum];
    }
