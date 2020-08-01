//need to use modulo in factorial also also return type of factorial is long long

class Solution {
public:
     long long factorial(int i)
    {
        return (i==0||i==1) ? 1 : (factorial(i-1)%1000000007*i%1000000007)%1000000007;
    }
    
    bool isPrime(int n)
    {
        if(n<=1)
            return false;
        if(n<=3)
            return true;
        if(n%2==0 || n%3==0)
            return false;
        for(int i=5; i*i<=n; i+=6 )
            if(n%i==0 || n%(i+2)==0)
                return false;
        return true;
    }
    int primeCount(int n)
    {
        int count = 0;
        for(int i=1; i<=n; i++)
            if(isPrime(i))
                count++;
        return count;
    }
    int numPrimeArrangements(int n) {
        int num = primeCount(n);
        return (factorial(num) % 1000000007*factorial((n - num))%1000000007)%1000000007;
    }
};
