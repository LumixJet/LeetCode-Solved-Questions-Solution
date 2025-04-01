class Solution {
public:
    static const long long MOD = 1e9 + 7; // defining MOD as a constant variable to handle large numbers in modulo operations
    
    long long findPower(long long a, long long b) // code for Fast Exponential Technique to find fast power of big number
    {
        if(b == 0) // base case : if b becomes 0 then we return 1
        {
            return 1;
        }
        long long half = findPower(a, b / 2); // to find (a)^b/2
        long long res = (half * half) % MOD; // then multiply with the same value as we need to find the square of a half
        if(b % 2 == 1) // if power which is given to us is odd power
        {
            res = (res * a) % MOD; // then we multiply extra a with result
        }
        return res; // at last we return final result we do each time modulo operation with MOD because the result can be very large
    }
    
    vector<int> getPrimes(int limit) // code for finding prime number within given range (sieve of Eratosthenes technique)
    {
        vector<bool> isPrime(limit + 1, true);
        vector<int> primes;
        
        for(int i = 2; i * i <= limit; i++) {
            if(isPrime[i]) {
                for(int j = i * i; j <= limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        for(int i = 2; i <= limit; i++) {
            if(isPrime[i]) {
                primes.push_back(i);
            }
        }
        return primes;
    }
    
    vector<int> findPrimeScores(vector<int>& nums) {
        int n = nums.size();
        vector<int> primeScores(n, 0);
        int maxElement = *max_element(nums.begin(), nums.end());
        vector<int> primes = getPrimes(maxElement);
        
        for(int i = 0; i < n; i++) {
            int num = nums[i];
            for(int prime : primes) {
                if(prime * prime > num) {
                    break;
                }
                if(num % prime != 0) {
                    continue;
                }
                primeScores[i]++;
                while(num % prime == 0) {
                    num /= prime;
                }
            }
            if(num > 1) {
                primeScores[i]++;
            }
        }
        return primeScores;
    }
    
    vector<int> findNextGreater(vector<int>& nums) {
        int n = nums.size();
        vector<int> nextGreater(n, n);
        stack<int> st;
        
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            nextGreater[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nextGreater;
    }
    
    vector<int> findPrevGreater(vector<int>& nums) {
        int n = nums.size();
        vector<int> prevGreater(n, -1);
        stack<int> st;
        
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            prevGreater[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return prevGreater;
    }
    
    int maximumScore(vector<int>& nums, int k) {
        vector<int> primeScores = findPrimeScores(nums);
        vector<int> nextGreater = findNextGreater(primeScores);
        vector<int> prevGreater = findPrevGreater(primeScores);
        
        int n = nums.size();
        vector<long long> subarrays(n, 0);
        
        for(int i = 0; i < n; i++) {
            subarrays[i] = (long long)(nextGreater[i] - i) * (i - prevGreater[i]);
        }
        
        vector<pair<int, int>> sortedNums(n);
        for(int i = 0; i < n; i++) {
            sortedNums[i] = {nums[i], i};
        }
        sort(sortedNums.begin(), sortedNums.end(), greater<>());
        
        long long score = 1;
        int idx = 0;
        while(k > 0) {
            auto [num, i] = sortedNums[idx];
            long long operations = min((long long)k, subarrays[i]);
            score = (score * findPower(num, operations)) % MOD;
            k -= operations;
            idx++;
        }
        return score;
    }
};
