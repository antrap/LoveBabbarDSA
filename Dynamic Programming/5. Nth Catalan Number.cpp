//Recursive Solution 
Catalan numbers satisfy the following recursive formula. 
//C_0=1 \ and \ C_{n+1}=\sum_{i=0}^{n}C_iC_{n-i} \ for \ n\geq 0           
  
  
  //Recursive Approach
  unsigned long int catalan(unsigned int n)
{
    // Base case
    if (n <= 1)
        return 1;
 
    // catalan(n) is sum of
    // catalan(i)*catalan(n-i-1)
    unsigned long int res = 0;
    for (int i = 0; i < n; i++)
        res += catalan(i)
            * catalan(n - i - 1);  //because C(n+1)=summation(0-n)--->C(i)*C(n+1-1-i)
 
    return res;
}

//Time complexity of above implementation is equivalent to nth catalan number. 

//T(n)=\sum_{i=0}^{n-1}T(i)*T(n-i-1) \ for \ n\geq 1;                                    

//The value of nth catalan number is exponential that makes the time complexity exponential.


//Tabulation
unsigned long int catalanDP(unsigned int n)
{
    // Table to store results of subproblems
    unsigned long int catalan[n + 1];
 
    // Initialize first two values in table
    catalan[0] = catalan[1] = 1;
 
    // Fill entries in catalan[] using recursive formula
    for (int i = 2; i <= n; i++) {
        catalan[i] = 0;
        for (int j = 0; j < i; j++)
            catalan[i] += catalan[j] * catalan[i - j - 1];
    }
 
    // Return last entry
    return catalan[n];
}

//Time Complexity: Time complexity of above implementation is O(n2)
