class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int n=nums.size(),i,j=1,count=1;
        if(n==0)
        {
            return 0;
        }
        for(i=0;i<n;i++)
        {
            while(j<n)
            {
                if(nums[i]!=nums[j])
                {
                    count++;
                    nums[i+1]=nums[j];
                    j++;
                    break;
                }
                else
                {
                    j++;
                }
            }
        }
        return count;
    }
};