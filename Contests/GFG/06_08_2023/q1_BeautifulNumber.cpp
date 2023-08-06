// Input:
// n = 19
// Output: 
// 1
// Explanation: 
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1
// 12 = 1


int squareSum(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool beautifulNumber(int n) {
        unordered_set<int> visited;

        while (n != 1) {
            if (visited.find(n) != visited.end())
                return false;

            visited.insert(n);
            n = squareSum(n);
        }

        return true;
    }
