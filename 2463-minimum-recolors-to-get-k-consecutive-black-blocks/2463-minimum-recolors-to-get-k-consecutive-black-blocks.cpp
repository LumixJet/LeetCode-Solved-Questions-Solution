class Solution {
public:
    int minimumRecolors(string blocks, int k) 
    {
        int mini = INT_MAX;
        int nums = blocks.size();

        for(int i=0; i<=nums-k; i++) //sliding window concept  
        {                            //Number of times we need to iterate for an entire array as per our window 
            int count = 0;
            for(int j=i; j<i+k; j++) //each time we iterate to a window which is equal to size of k 
            {
                if(blocks[j] == 'W') //count number of W which is present in current window
                {
                    count ++;
                }
            }
            mini = min(mini, count); //window having minimum number of W that much number of operation we require 
        }                           //to Recolor K consecutive Black Blocks
        return mini;
    }
};