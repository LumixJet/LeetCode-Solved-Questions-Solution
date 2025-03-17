class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) 
    {
        int n = colors.size();
        int nums = n + (k-1); //So we append array as with k-1 tiles as we dont want to check
                             //for circular each time in colors array now we check only linear
        for(int i=0;i<k-1;i++)
        {
            colors.push_back(colors[i]); //append k-1 tiles in back side of colors array
        }

        int i = 0; //i and j are the pointers where j will run forward and find the valid window and 
        int j = 1; //with help of i we will shrink the window and find new window 
        int ans = 0;

        while(j < nums) //traverse entire array nums
        {
            if(colors[j] == colors[j-1]) //if current colors is same as previous color 
            {
                i = j; //then that is not valid window so we need to now start from j afterwards
                j ++; //make i pointing to j and increament j and continue
                continue;
            }
            if(j-i+1 == k) //if we find a valid window of size k then we need to increament ans and
            {              //now we shrink the window with help of i from left side and find new window
                ans ++;   //with help of j pointer 
                i ++;
            }
            j++;
        }

        return ans; //after traversing entire nums array we have total answer in ans and we return that 
    }
};