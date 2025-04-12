class Solution {
public:
    int n;
    bool solve(vector<int> &nums, int i, int target, vector<vector<int>> &dp)
    {
        if(i >= n || target < 0) //base case : if i becomes out of bound or target becomes less than 0 then that means 
        {
            return false; //now it is not possible to find a valid partition in array having both equal sum 
        }
        if(target == 0) //if target becomes equal to zero then that means that we findhe partition such that both partition 
        {
            return true; //will have equal sum so we return true
        }
        if(dp[i][target] != -1) //if result of that partiton is compuuted earlier then we dont compute it again we just return 
        {
            return dp[i][target]; //the stored result in dp array 
        }

        bool include = solve(nums,i+1,target-nums[i],dp); //recursive call to include current element which is present in nums array
        bool exclude = solve(nums,i+1,target,dp); //recursive call to exclude current element which is present in nums array

        return dp[i][target] = (include || exclude); //if any one include or exclude is true we return true that it is possible.
    }
    bool canPartition(vector<int>& nums) 
    {   
        n = nums.size();
        int sum = 0; //variable to find the sum of all the numbers present in array

        for(int i=0;i<n;i++) //to compute the sum of all the numbers present in array
        {
            sum += nums[i];
        }

        if(sum % 2 != 0) //if sum of entire array is odd then we cant divide the array 
        {
            return false; //into 2 equal partition having same sum
        }

        int target = sum/2; //divide sum by half as that is target value which should be present by one partition

        vector<vector<int>> dp(n,vector<int> (target+1, -1)); //to find subset we use recurssion we and we optimize using DP memorization

        return solve(nums,0,target,dp); //calling function solve to find partition having equal sum of another partiton 
    }
};