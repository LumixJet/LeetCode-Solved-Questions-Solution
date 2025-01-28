class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) 
    {
        long long mini = 0;
            
        int nums = arr.size();
        for (int i = 0; i < nums; i++) //Without rearranging, find cost to make arr brr identical 
        {
            mini += abs(arr[i] - brr[i]); //find abs diff between elements of both array and total
        }//sum of differences of all elements will be cost to make arr brr identical without rearrange 
        
        if (nums > 1) // With rearranging, find cost
        { 
            sort(arr.begin(), arr.end()); //sort arr brr because in that way we get elements arranged in fashion
            sort(brr.begin(), brr.end()); //so that there difference is less so we will be abe to min cost 
            
            long long cost = 0;
        
            for (int i = 0; i < nums; i++) 
            {
                cost += abs(arr[i] - brr[i]); //find abs diff between elements of both array and total
            }//sum of differences of all elements will be cost to make arr brr identical with rearrange
        
            cost += k; //as we sorted the array so split cost will be added in cost too.

            return min(mini, cost); // Min cost of both rearranged or not rearranged
        }
        
        return mini;  //If there is only a single element in the array
    }
};
