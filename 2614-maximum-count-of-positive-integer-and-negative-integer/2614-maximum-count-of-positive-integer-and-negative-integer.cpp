class Solution {
public:
    int maximumCount(vector<int>& nums) 
    {
        int n = nums.size(); //use multiset as duplicate +ve or -ve numbers can be present
        multiset<int> st1; //store -ve numbers present in nums
        multiset<int> st2; //store +ve numbers present in nums
        for(int i=0;i<n;i++)
        {
            if(nums[i] < 0) //if current element of nums is less than 0 that means it is negative number
            {
                st1.insert(nums[i]); //we insert in st1
            }
            else if(nums[i] > 0) //if current element of nums is greater than 0 that means its a positive number
            {
                st2.insert(nums[i]); //we insert in st2
            }
        }
        if(st1.size() > st2.size()) //if size of st1 is greater than st2 that means negative number size is
        {                                                             //greater than positive numbers in nums
            return st1.size(); //so we return size of negative numbers
        }
        else //otherwise positive number is more than negative number 
        {
            return st2.size(); //therefore we return size of positive numbers present in nums
        }    
    }
};