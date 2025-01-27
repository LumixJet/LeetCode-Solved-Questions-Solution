class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) 
    {
        int n = nums.size();
        vector<int> arr = nums; //to sort and find group of numbers

        int group = 0;
        sort(arr.begin(),arr.end());

        unordered_map<int,int> gNo;//to store group number of value
        unordered_map<int, list<int>> gVal; //to store all val of each group in sorted form  
        gNo[arr[0]] = group;
        gVal[group].push_back(arr[0]);

        for(int i=1;i<n;i++)
        {
            if(abs(arr[i] - arr[i-1]) > limit)
            {                      //if adjacent element difference is greater than limit
                group = group + 1; //that means that element is part of other group
            }
            gNo[arr[i]] = group;
            gVal[group].push_back(arr[i]);
        }

        //finally building answer by placing each group smallest value at its group
        vector<int> res(n); //current value which is present in first place of array 
        for(int i=0;i<n;i++)
        {
            int gp = gNo[nums[i]]; //to know group number
            res[i] = gVal[gp].front(); //get that group number in that place 
            gVal[gp].pop_front(); //remove that value
        }
        return res; //finally returning result which holds smallest lexographic order array
    }              //which follows the given condition  |nums[i] - nums[j]| <= limit
};