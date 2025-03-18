class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) 
    {
        int n = nums.size();
        int res = 0; //variable to store final answer

        for(int i=0;i<n;i++) //iterate nums array 
        {
            int mask = 0; //mask number to find valid window 

            for(int j=i;j<n;j++) //start from i and afterwards each time 
            {
                if((mask & nums[j]) != 0) //if current number AND operation is not equal to 0 completely then that number will 
                {                        //not be included in a valid window so we try to find a new valid window
                    break;  
                }

                mask = (mask | nums[j]); //once we find valid window then we do OR operation with numbers to get at what position
                                                            //bit should not be 1 for next number to get included in a valid window
                res = max(res, j-i+1); //store ans in res
            }
        }
        return res; //return longest nice subarray which is present in nums
    }
};