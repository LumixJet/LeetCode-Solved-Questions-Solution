class Solution {
public:
    bool isFesiable(vector<int> &nums, int mid, int k) 
    {
        int n = nums.size();
        int house = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] <= mid) //if money in house is small or equal to mid(max money)
            {
                i++; //robber steals it and jumps to next adjacent house 
                house ++; //also we increase the count of house from where robber steals money
            }
        }                   //if house count is more than k from which robber steals money 
        return house >= k; //than max money(mid) is a possible answer
    }
    int minCapability(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int mini = *min_element(nums.begin(),nums.end()); //min money which a robber can steal
        int maxi = *max_element(nums.begin(), nums.end()); //max money which a robber can steal

        int ans = maxi; //initialize ans as max money which a robber can steal

        while(mini <= maxi)
        {
            int mid = (mini + maxi) / 2; //say max money equal to mid can be stealed by robber

            if(isFesiable(nums,mid,k)) //if max money(mid) and robber can steal from k or more 
            {                   
                ans = mid; //house we make mid as answer and we need to minimize max money
                maxi = mid - 1; //which robber can steal from k or more houses we do
            }                  //make high as mid -1
            else
            {
                mini = mid + 1; //if current max money(mid) robber cannot steal from k or more
            }                 //than k house we increase the max money so we make low as mid+1 
        }    

        return ans; //at last we return min of max money which a robber can steal if we steals
    }              //from k or more than k houses 
};