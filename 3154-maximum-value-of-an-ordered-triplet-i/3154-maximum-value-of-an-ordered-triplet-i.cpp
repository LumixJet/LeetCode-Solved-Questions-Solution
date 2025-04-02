class Solution {
public:
    long long maximumTripletValue(vector<int>& nums)  
    {
        int n = nums.size(); 
        if(n < 3) //base case: if there are less than 3 numbers present in nums then we return 0
        {
            return 0; //as it is not possible to make triplet
        }
        vector<int> maxi(n,0); //vector to store max element in right side of current element in nums array 

        maxi[n-1] = nums[n-1]; //initially as we know the right most element in nums array will be max of itself

        for(int i=n-2;i>=0;i--) //start traversing from right side of array nums
        {   
            maxi[i] = max(nums[i], maxi[i+1]); //storing max element which is present in right side of current element
        }

        long long ans = 0; //to store final answer which will hold maximum value possible of an order triplet
        
        for(int i=0;i<n-2;i++) //traversing element and this marks current element index which we are focusing now
        {
            int mini = INT_MAX; //mini variable to find minimum element present in right side of nums

            for(int j=i+1;j<n-1;j++) //traversing from right side just after current element in nums
            {
                mini = min(mini,nums[j]); //finding min element present in nums at right side of current element nums[i]

                if(j+1 < n) //through this condition we check in bound condition 
                {
                    long long res = 1LL * (nums[i] - mini) * maxi[j+1]; //min element next index in maxi will consist 
                    ans = max(ans, res); //max element present in right side of nums array in right of mini element
                }                       //we compute for all ans one by one and max out of all will be our final ans
            }
        }
        return ans; ///at last we return final answer which is max value of order pair triplet
    }
};