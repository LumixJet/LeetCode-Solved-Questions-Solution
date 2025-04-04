class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) 
    {
        int n = weights.size(); //getting the size of weights array
        int m = n-1; //size of pairSum array as pairs will have always -1 size of original array

        vector<int> pairSum(m,0);
        for(int i=0;i<m;i++)        //computing result for pair sum array 
        {
            pairSum[i] = weights[i] + weights[i+1]; //finding weights or sum of corresponding pairs
        }

        sort(pairSum.begin(),pairSum.end()); //sort the pair Sum array in ascending order

        long long minSum = 0; //variable to find the sum of minimum pair 
        long long maxSum = 0; //variable to find the sum of maximum pair

        //As we have sorted the pairSum array in ascending order so to find answer for k bags we need to find min and max
        //pair sum for k-1 pairs as that will give me correct answer 
        for(int i=0;i<k-1;i++)
        {
            minSum += pairSum[i]; //min scores for k-1 pairs from pairSum array as in start pair will have min scores
            maxSum += pairSum[m-i-1]; //max scores for k-1 pairs from pairSum array as in end pair will have max scores
        }

        return maxSum - minSum; //At last we return ans as difference between max and min scores among marble distribution
    }
};