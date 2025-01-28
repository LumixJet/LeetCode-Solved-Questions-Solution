class Solution {
public:
    int subarraySum(vector<int>& arr) 
    {
        int nums = arr.size();
        vector<int> prefix(nums+1,0);
        
        for(int i=0;i<nums;i++)//calculating prefix sum of entire array
        {
            prefix[i+1] = prefix[i] + arr[i]; 
        }
        
        int tot = 0;
        for(int i=0;i<nums;i++) //calculate sum of all subarray and store in tot
        {
            int start = max(0, i - arr[i]);
            tot += prefix[i+1] - prefix[start];
        }
        return tot;
    }
};