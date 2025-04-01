class Solution {
public:
    const int MOD = 1e9 + 7;
    long long findPower(long long a, long long b) //code for Fast Exponential Technique to find fast power of big number
    {
        if(b == 0) //base case : if b becomes 0 then we return 1 
        {
            return 1;
        }
        long long half = findPower(a, b/2); //to find (a)^b/2
        long long res = (half * half) % MOD; //then multiply with the same value as we need to find the square of a half

        if(b % 2 == 1) //if power which is given to us is odd power 
        {
            res = (res * a) % MOD; //then we add extra a with result
        }

        return res; //at last we return final result we do each time modulo operation with MOD because the result can be very large
    }
    vector<int> getPrimes(int limit) //code for finding prime number within given range (sieve of erasthonesis technique)
    {
        vector<bool> isPrime(limit+1, true); //initially mark all values as true but this vector consist all values which are prime as true

        for(int i=2;i*i<=limit;i++) //start from 2 onwards to find prime numbers till given limits
        {   
            if(isPrime[i]) //if we get the number which is prime 
            {
                for(int j=i*i;j<=limit;j+=i) //then we mark all the numbers which are its multiple and come under the limit as false 
                {
                    isPrime[j] = false;
                }
            }
        }

        vector<int> primes;
        for(int i=2;i<=limit;i++) //we iterate all the numbers again from 2 onwards till given limits
        {
            if(isPrime[i]) //if we find a number is true in isPrime vector that means that number is a prime number 
            {
                primes.push_back(i); //so we push that number in primes vector
            }
        }

        return primes; //at last we return primes vector which consist all the prime number which are prime till given limit 
    }
    vector<int> findPrimeScores(vector<int> &nums) //function to calculate prime scores of each number present in nums
    {
        int n = nums.size();
        vector<int> primeScores(n,0); //this will count prime scores of each element present in nums

        int maxi = *max_element(nums.begin(),nums.end()); //find max element present in nums as maximum prime factor for any number can go till this

        vector<int> primes = getPrimes(maxi); //primes vector has all prime factor stored of max element present in nums

        for(int i=0;i<n;i++) //traversing nums array to find prime score of each number present in nums
        {
            int num = nums[i]; //getting hold in num of current number present in nums

            for(int prime : primes) //traversing primes vector which holds all the prime factor of max element present in nums
            {
                if(prime*prime > num) //case - if current prime factor of max element is greater than square root of current number present in nums
                {
                    break; //then we break the loop as we cant find more prime factor for a number then its square root
                }
                if(num % prime != 0) //case - if current number of nums is not divisble by current prime factor of max element present in nums 
                {
                    continue; //we continute loop as that prime factor of max element is not prime factor of current element of nums
                }
                primeScores[i] ++; //if all the cases does not run then that means that current prime factor of max element is also prime factor of current 
                                                                                                                                  //element present in nums
                while(num % prime == 0) //as that number can be again divided by current prime factor of max element
                {
                    num /= prime; //so we keep on dividing that number till that number does not become indivisible by current factor of max element
                }                //because we need to find the prime score which is (number of distict prime factor of current number in nums)
            }
            
            if(num > 1) //case of number like 15 -> 3, 5(which will not get counted in prime scores because of condition prime*prime > num)
            {
                primeScores[i] ++; //so we increase prime score of that number for last factor which is not included
            }
        }
        return primeScores; //at last return primeScores vector which store prime score of each number present in nums
    }
    vector<int> findNextGreater(vector<int> &primeScores) //function to find next greater prime score element present in nums
    {
        int n = primeScores.size(); //to get size of primeScores vector 

        vector<int> nextGreat(n,n); //vector to store element having next greater prime score to current number
        stack<int> st; //stack to perform operation to find next greater prime score of element than current element

        for(int i=n-1;i>=0;i--) //start traversing from right of nums array 
        {
            while(!st.empty() && primeScores[st.top()] <= primeScores[i]) //if stack is not empty and prime score of number present at top of stack is less 
            {                                                            //than current element prime score that means current number is new next greater 
                st.pop(); //element having prime score so we later push index of this number into top of stack
            }

            nextGreat[i] = st.empty() ? n : st.top(); //if stack got empty due to while loop case or else that means there is no element in right having greater
            st.push(i); //prime score than current element so we store out of bound value also we push current element index in stack top for other left values 
        }               //in nums

        return nextGreat; //at last we return nextGreat vector which stores index of each value next greater element
    }
    vector<int> findPrevGreaterEqual(vector<int> &primeScores) //function to find previous greater or equal prime score element
    {
        int n = primeScores.size(); //getting size of primeScore vector

        vector<int> prevGreat(n, -1); //vector to store index of number which are having prime score greater or equal to current number prime score at left
        stack<int> st; //stack to perform operation to find previous element having equal or greater prime score in left side
        
        for(int i=0;i<n;i++) //start traversing nums array from left side 
        {
            while(!st.empty() && primeScores[st.top()] < primeScores[i]) //if stack is not empty and prime score of top element present in stack is less 
            {                                                           //than current element prime score then we pop the element from stack top as now
                st.pop(); //we got the new previous greater or equal prime score element
            }

            prevGreat[i] = st.empty() ? -1 : st.top(); //if stack is empty due to while loop or other case than we put -1 denoting no element is present in left
            st.push(i); //of current element which is having greater or equal prime score
        }

        return prevGreat; //at last we return prevGreat vector which stores index of all element previous greater or equal prime score
    }
    int maximumScore(vector<int>& nums, int k) 
    {
        vector<int> primeScores = findPrimeScores(nums); //calling function sieve of erasthonesis to find prime factors of max element present in nums
        vector<int> nextGreater = findNextGreater(primeScores); //calling function to find index for each number in nums next element having greater prime score
        vector<int> prevGreaterEqual = findPrevGreaterEqual(primeScores); //same to find index of each number in nums previous element haing greater or equal 
                                                                            //prime scores 
        int n = nums.size(); 
        vector<long long> subArray(n,0); //to count for each number it can get multiplied in score how many such subarray that number forms

        for(int i=0;i<n;i++) //to find number of subarray can be made for each number in which current number will be multiplied as prime score
        {              
            //nextGreater[i] - i gives number of possible ending points of such subarray                                                                                                                       
            subArray[i] = (long long)(nextGreater[i] - i) * (i - prevGreaterEqual[i]); //whole gives total subarray in which element at index i will be 
        }                                                                       //multiplied into score

        vector<pair<int, int>> sortedNums(n); //as we want to sort the number in descending order but index of number will get disturbed so we 
        for(int i=0;i<n;i++) //first store in sortedNums array number and its corresponding original index where it is located in nums
        {
            sortedNums[i] = {nums[i], i};
        }

        sort(sortedNums.begin(), sortedNums.end(), greater<>()); //sort entire sorted array in descending order to maximize score

        long long score = 1; //maximum score which we will make from nums array initially it will be 1

        int index = 0; //start from largest element in nums which is stored in start of sortedNums array
        while(k > 0)
        {
            auto [num , i] = sortedNums[index]; //take the largest element present in nums and its index and store in num and i correspondingly

            long long ops = min((long long)k, subArray[i]); //this much time the num (largest value) will be multiplied in score

            score = (score * findPower(num, ops)) % MOD; //so we multiply in score as many time num(largest value) as ops 

            k = (k - ops); //so subtract k with ops(number of times num(largest value) is multiplied in score)

            index ++; //as we shift to next greater element present in sortedNums as all subarray where current number will be multiplied in score is over
        }
        return score; //at last we return max score which we can make from nums array as per given condition in questions
    }   
};