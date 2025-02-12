class Solution {
public:
    int maximumSum(vector<int>& nums) 
    {
        int n = nums.size();
        int maxi = -1;
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++)
        {
            int temp = nums[i];
            int sum = 0;
            while(temp > 0)
            {
                sum += temp % 10;
                temp /= 10;
            }
            if(mpp.find(sum) != mpp.end())
            {
                maxi = max(maxi, mpp[sum] + nums[i]);
            }
            mpp[sum] = max(mpp[sum], nums[i]);
        }
        return maxi;
    }
};