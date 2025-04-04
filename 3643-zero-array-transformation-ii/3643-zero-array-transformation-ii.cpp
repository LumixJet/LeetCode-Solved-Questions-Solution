class Solution {
public:
    int n; //for holding the size of nums  
    int Q; //for holding the size of queries 

    bool checkDiffArray(vector<int> &nums, vector<vector<int>> &queries, int k) //standard difference array technique code 
    {
        vector<int> diff(n,0);//create a difference array initialized all cells of array with 0

        for(int i=0;i<k;i++) //process all queries till k length 
        {
            int l = queries[i][0]; //hold of start index of current query
            int r = queries[i][1]; //hold of end index of current query
            int val = queries[i][2]; //value which can be atmost subtracted and added from the range of indexes mentioned in queries

                                                                                        //performing Difference array technique
            diff[l] += val; //add val to start index mentioned in query in diff array 
            if(r+1 < n) //if end+1 index of query is in bound 
            {
                diff[r+1] -= val; //subtract val from end+1 index mentioned in query from diff array
            }
        }
        int cumSum = 0; //hold the cumilative sum of the diff array
        for(int i=0;i<n;i++)
        {
            cumSum += diff[i]; //calculating cumilative sum from difference array till index i

            diff[i] = cumSum; //hold cumilative sum in diff array at respective index 

            if(nums[i] - diff[i] > 0) //as diff array says max change which can be made after processing k number of queries
            {                        //if subtracting number present at index i from diff[i] does give value greater than 0 that 
                return false; //means we cant form 0 in nums at that index so we return false that we need more queries
            }
        }
        return true; //if all the indexes of nums we are able to form 0 with k number of queries we return true 
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) 
    {
        n = nums.size(); //storing the size of nums array 
        Q = queries.size(); //storing the size of queries array

        auto lambda = [](int x) 
        {
            return x == 0; //lambda function which return true when x is 0
        };

        if(all_of(nums.begin(),nums.end(),lambda)) //STL which sends all element present in nums to labda function
        {
            return 0; //if all elements present in nums are 0 then we return 0 as no operation is required to make nums as 0 array
        }

        int l = 0; //taking l and r to perform binary search on queries to optimally find minimum number of queries which are 
        int r = Q-1;                                                                    //required to make nums as zero array
        int k = -1; //to store final answer minimum number of queries which are required to make nums as zero array

        while(l <= r) //performing binary search on queries
        {
            int mid = (l+r)/2; //computing mid for the query
            if(checkDiffArray(nums,queries,mid+1)) //performing difference array technique till mid+1 queries and if it returns true 
            {
                k = mid+1; //then we mark mid+1 as answer and make r as mid-1 to find minimum number of queries whoich are
                r = mid-1; //required to make nums array as zero array 
            }   
            else //if queries till mid+1 is not able to make nums array as zero array then we make l as mid+1 to increase  the 
            {               //query range so that we can make nums array as zero array
                l = mid+1;
            }
        }
        return k; //at last we return k which has minimum number of queries which are required to make nums array as zero array 
    }//if it is not possible to do so then k has -1 present in it which we return showing its not possible to make nums as zero array 
};