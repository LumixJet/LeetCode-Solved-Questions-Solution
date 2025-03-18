class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) 
    {
        int n = nums.size();

        int i=0; //using sliding window approach to find longest nice subarray where j will go forward and
        int j=0; //find valid window and if we get valid window then we shrink the window  to get new 
                                                                    //valid window by moving i forward
        int res = 1; //by defult 1 size window will be always possible
        int mask = 0; //use to find new number where all it should not have 1 present to be in valid window

        while(j < n)
        {
            while((mask & nums[j]) != 0) //perform AND operation with mask and current element if it does 
            {                                       //not gives 0 then we shrink window to find new window

                mask = (mask ^ nums[i]); //shrink using XOR with current mask and number pointed by i 
                i++; //increase i as we skiped now previous pointed i number from window 
            }
            res = max(res, j-i+1); //find longest nice subarray which is possible in nums
            mask = (mask | nums[j]); //update mask with current element if it gets included in current 
            j++;                  //valid window and increase j pointer to see new element for valid window
        }

        return res; //return final result which store length of longest nice subarray 
    }
};