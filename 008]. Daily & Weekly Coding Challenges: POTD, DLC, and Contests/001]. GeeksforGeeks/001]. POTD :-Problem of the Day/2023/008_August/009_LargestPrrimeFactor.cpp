class Solution{
public: 
    long long int largestPrimeFactor(int N){
        // code here
        //for every number N ther exist a prime factor till sqrt(N)
        //PRIME NUM CAN BE REPRESENTED BY---(P^X)(P^Y)(P^Z)
        
             int ans;
        
        for(int i = 2; i * i <= N; i++){
            if(N % i == 0){
                ans = i;
                while(N % i == 0){
                    N /= i;              //REMOVING first prime number 
                }
            }    
        }
        
        if(N > 1)   // at last there N could be 1 or any prime numbers multiplication so take max among them
            ans = max(ans, N);
            
            
        return ans;
    }
};
