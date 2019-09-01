//https://leetcode.com/problems/prime-arrangements/

class Solution {
public:
    const int M = 1000000007; 
    bool isPrime(int n) { 
        if (n <= 1) 
            return false; 
        for (int i = 2; i < n; i++) 
            if (n % i == 0) 
                return false; 
        return true; 
    }
    
    long long int factorial(int n){ 
        long long int f = 1; 
        for (int i = 1; i <= n; i++) 
            f = (f * i)%M;  
        return f % M; 
    } 
    
    
    int numPrimeArrangements(int n) {
        int count=0;
        for(int i=2;i<=n;i++)
            if(isPrime(i)) count++;
        return (factorial(count)*factorial(n-count)%M);
    }
};
