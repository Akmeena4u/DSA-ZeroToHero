The Sieve of Eratosthenes is an ancient algorithm used to find all prime numbers up to a specified integer. It is named after the Greek mathematician Eratosthenes, who devised it around 240 BC. The algorithm efficiently marks the non-prime numbers (composites) in a list, leaving only the primes.

### How the Sieve of Eratosthenes Works

1. **Create a List**:
   - Start with a list of consecutive integers from 2 to the desired maximum number \( n \).

2. **Initial Marking**:
   - Assume all numbers in the list are prime.

3. **Eliminate Multiples**:
   - Begin with the first prime number (2). Mark all of its multiples as non-prime.
   - Move to the next number in the list that is still unmarked (which will be a prime), and mark all of its multiples as non-prime.
   - Repeat this process for the next unmarked number, and continue until you've processed numbers up to the square root of \( n \).

4. **Collect Primes**:
   - The remaining unmarked numbers in the list are prime.



### Example

Let's find all primes up to 30.

1. Start with a list of numbers from 2 to 30:
   ```
   2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30
   ```

2. The first number is 2. Mark all multiples of 2 (except 2 itself) as non-prime:
   ```
   2, 3, x, 5, x, 7, x, 9, x, 11, x, 13, x, 15, x, 17, x, 19, x, 21, x, 23, x, 25, x, 27, x, 29, x
   ```

3. The next number is 3. Mark all multiples of 3 (except 3 itself) as non-prime:
   ```
   2, 3, x, 5, x, 7, x, x, x, 11, x, 13, x, x, x, 17, x, 19, x, x, x, 23, x, 25, x, x, x, 29, x
   ```

4. The next number is 5. Mark all multiples of 5 (except 5 itself) as non-prime:
   ```
   2, 3, x, 5, x, 7, x, x, x, 11, x, 13, x, x, x, 17, x, 19, x, x, x, 23, x, x, x, x, x, 29, x
   ```

5. Continue this process for the next numbers (7, 11, 13, 17, 19, 23, 29), but since their multiples are already marked, the list remains the same.

6. The remaining unmarked numbers are:
   ```
   2, 3, 5, 7, 11, 13, 17, 19, 23, 29
   ```

These are the prime numbers up to 30.

### Implementation in C++

## Brute Force approach

### Brute Force Approach to Find Prime Numbers

The brute force approach to find all prime numbers up to a given integer \( n \) involves iterating over all numbers from 2 to \( n \) and checking each one for primality.

#### Algorithm:

1. **Initialization**:
   - Create an empty array (vector) to store the prime numbers found.

2. **Iterate and Check for Primality**:
   - Iterate over each number \( i \) from 2 to \( n \).
   - For each number, check if it is prime using a function (`isPrime`).

3. **Check for Prime**:
   - The `isPrime` function checks if a number \( n \) has exactly two divisors: 1 and \( n \).
   - It does this by iterating from 1 to the square root of \( n \) and counting the divisors.

4. **Store and Return Primes**:
   - If a number is prime, add it to the array.
   - After iterating through all numbers, return the array containing all prime numbers.

#### Detailed Steps with Code:

```cpp
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    // Counter to count the number of divisors of n
    int cnt = 0; 
    
    // Loop from 1 to the square root of n
    for(int i = 1; i * i <= n; i++) { 
        // Check if i is a divisor of n
        if(n % i == 0) {
            // Increment the count of divisors
            cnt++; 
            
            // Check if i is not the square root of n
            if((n / i) != i) {
                // Increment the count of divisors again
                cnt++; 
            }
        }
    }
    
    // Check if the number of divisors is exactly 2
    if(cnt == 2) { 
        // If there are exactly 2 divisors, return true (prime)
        return true; 
    }
    
    // If the number of divisors is not 2, return false (not prime)
    return false; 
}

// Function to find all prime numbers up to 'n'
vector<int> findAllPrimes(int n) {
    // Initialize an empty vector to store the prime numbers
    vector<int> ans;
    
    // Iterate from 2 to 'n'
    for (int i = 2; i <= n; i++) {
        // Check if the current number 'i' is prime
        if (isPrime(i)) {
            // If 'i' is prime, add it to the vector 'ans'
            ans.push_back(i);
        }
    }
    
    // Return the vector containing all prime numbers up to 'n'
    return ans;
}

int main() {
    int n = 32;
    vector<int> primes = findAllPrimes(n);

    cout << "Prime numbers less than or equal to " << n << ":" << endl;
    for (int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}
```

#### Explanation of the Code:

1. **`isPrime` Function**:
   - The function checks if a given number \( n \) is prime.
   - It initializes a counter `cnt` to count the number of divisors.
   - It loops from 1 to the square root of \( n \). For each divisor \( i \), it checks if \( i \) divides \( n \) without a remainder.
   - If \( i \) is a divisor, it increments the counter. If \( i \) is not the square root of \( n \), it counts \( n / i \) as another divisor.
   - Finally, if the number of divisors is exactly 2, the function returns `true` (indicating \( n \) is prime); otherwise, it returns `false`.

2. **`findAllPrimes` Function**:
   - This function finds all prime numbers up to \( n \).
   - It initializes an empty vector `ans` to store the prime numbers.
   - It iterates from 2 to \( n \). For each number \( i \), it calls the `isPrime` function.
   - If `isPrime` returns `true`, it adds \( i \) to the vector `ans`.
   - Finally, it returns the vector `ans` containing all prime numbers up to \( n \).

3. **`main` Function**:
   - The main function sets \( n = 32 \) and calls `findAllPrimes(n)` to get all primes up to 32.
   - It then prints the prime numbers.

### Notes:

- **Efficiency**: The brute force approach checks each number up to \( n \) for primality individually, resulting in a time complexity of \( O(n \sqrt{n}) \). This is not the most efficient method for large \( n \).
- **Prime Check**: The `isPrime` function is a simple method to check if a number is prime, based on counting divisors up to the square root of the number.
- **Vector Usage**: The use of a vector to store prime numbers allows dynamic resizing and easy handling of the list of primes.


---
## Optimized Approach

The Sieve of Eratosthenes algorithm is efficient for finding all prime numbers up to a given limit \( n \). Here, I'll break down the algorithm step-by-step and explain the provided C++ code.

### Algorithm Explanation

1. **Initialization**:
   - Create a vector `prime` of size \( n+1 \) initialized to 1, assuming all numbers are prime initially. The `prime` vector will store the status of all numbers from 2 to \( n \), whether they are prime or not.
   - Set `prime[0]` and `prime[1]` to 0 because 0 and 1 are not prime numbers.

2. **Sieve Process**:
   - Iterate from 2 to the square root of \( n \). For each number \( i \):
     - If `prime[i]` is 1, it means \( i \) is a prime number.
     - Mark all multiples of \( i \) (starting from \( i*i \) to \( n \)) as not prime by setting `prime[j]` to 0.

3. **Collect Primes**:
   - Iterate through the `prime` vector from 2 to \( n \). If a number \( i \) is still marked as prime (`prime[i]` is 1), add it to the result vector `ans`.

### Code Explanation

```cpp
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

// Function to find all prime numbers up to 'n'
vector<int> findAllPrimes(int n) {
      // Initialize with 1 (assuming all numbers are prime initially)
    vector<int> prime(n + 1, 1);
    
    // 0 and 1 are not prime
    prime[0] = prime[1] = 0; 
    
    // Apply Sieve of Eratosthenes
    for (int i = 2; i <= sqrt(n); ++i) {  //runs loop for sqrt(n) only because after that there will be similarity only 
        if (prime[i] == 1) {// means if i is not prime then mark all multiples as a prime
            for (int j = i * i; j <= n; j += i) {  // started from i*i as a optimization  , otherwise in brute force it was started from 2*i
                // Mark multiples of prime numbers as not prime
                prime[j] = 0; 
            }
        }
    }
    
    vector<int> ans;
    // Collect prime numbers
    for (int i = 2; i <= n; ++i) {
        if (prime[i] == 1) {
            ans.push_back(i);
        }
    }
    return ans;
}

int main() {
    int n = 32;
    vector<int> primes = findAllPrimes(n);

    cout << "Prime numbers less than or equal to " << n << ":" << endl;
    for (int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}
```

Here are the notes on the complexity analysis of the Sieve of Eratosthenes algorithm:

### Time Complexity:
- **Upper Bound:** O(N + N*log(log(N)))
  - The outer loop iterates from 2 to the square root of \( n \), which is O(sqrt(n)) iterations.
  - The inner loop iterates over multiples of each prime number found, marking them as not prime.
  - In total, the number of operations performed is approximately O(n/2 + n/3 + n/5 + …), which is equivalent to O(n log(log(N)) operations due to the prime number distribution.
  
### Space Complexity:
- **Upper Bound:** O(N)
  - Additional space proportional to the input size is needed to store a vector of size ‘n+1’ to store whether each number up to \( n \) is prime.
  - The space complexity is linearly related to the input number \( n \).
```

### Summary
The Sieve of Eratosthenes is a highly efficient algorithm for finding all prime numbers up to a given number \( n \). It works by iteratively marking the multiples of each prime number starting from 2. The result is a list of primes up to \( n \) in an optimized manner compared to checking each number individually.

