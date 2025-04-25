class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_set<int> st(nums.begin(),nums.end()); //store all distict values which are present in array nums
        int count = st.size(); //size of unordered set will tell us number of distinct values which are present in nums

        st.clear(); //now we clear the set to use it in next use case 
        int res = 0; //also use res variable to store the result

        for(int i=0;i<n;i++) //now we iterate the array nums
        {
            for(int j=i;j<n;j++) //also use 2-pointer technique and each time our j will start running from i current index
            {
                st.insert(nums[j]); //now we insert the number in set 
                if(st.size() == count) //we check weather each time size of set is same as number of distict elements 
                {                                                               //present in set if this condtiion is satisfied
                    res ++; //we increase count means we find new complete subarray 
                    res += n-j-1; //moreover now all the elements which are remaining in right will compute to complete array
                                                                                            //so we add that much in res number
                    break; //also we break from the loop to count for new complete subarray
                }
            }
            st.clear(); //each time after finding a complete subarray we clear the set for finding new complete subarray
        }

        return res;  //at last we return number of complete subarray count which was possioble to make from nums
    }
};