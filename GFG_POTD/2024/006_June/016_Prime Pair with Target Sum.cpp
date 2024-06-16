  vector<int> getPrimes(int n) {
        // code here
        // used sieve of Eratosthenes.
        bool prime[n+1];
        memset(prime,true,sizeof prime);
        prime[0]=false;
        prime[1]=false;
        for(int i=2;i*i<=n;i++){
            if(prime[i]){
                for(int j=i*i;j<=n;j+=i)prime[j]=false;
            }
        }
        for(int i=2;i<=n;i++){
            if(prime[i] and prime[n-i])return {i,n-i};
        }
        return {-1,-1};
    }
