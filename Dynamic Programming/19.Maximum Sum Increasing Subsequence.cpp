int maxSumIS(int arr[], int n)  
	{
	    int max_inc_sub_arr[n];
	    
	    for(int i=0;i<n;i++){
	        max_inc_sub_arr[i]=arr[i];
	    }
	    
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(arr[i]>arr[j])
	                max_inc_sub_arr[i]=max(max_inc_sub_arr[i],max_inc_sub_arr[j]+arr[i]);
	        }
	    }
	    int max= max_inc_sub_arr[0];
	    for(int i=0;i<n;i++){
	        if( max_inc_sub_arr[i]>max)
	        max= max_inc_sub_arr[i];
	    }
	    
	    
	    return max;
	}  

Time Complexity: O(n^2) 
Space Complexity O(n) 
