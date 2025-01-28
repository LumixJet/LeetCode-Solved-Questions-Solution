class Solution {
public:
    int maxAdjacentDistance(vector<int>& arr) 
    {
        int maxi = 0; //to store max difference b/w adjacent element in circular array 
        int diff = 0; //to store difference b/w adjacent element 
        int nums = arr.size();
        
        if(nums < 2) //if size of array is less that 2 then we cant find difference 
        {               //between the elements because there is only 1 element in array
            return 0;
        }
        
        maxi = abs(arr[nums-1] - arr[0]); //as array is circular so last element 
                                    //adjacent will be 1st element so store result in maxi 
                                   //difference between last and 1st element initially
        for(int i=0;i<nums -1;i++)
        {
            diff = abs(arr[i] - arr[i+1]); //calculate difference b/w adjacent element 
            maxi = max(maxi, diff); //of array and store max of all difference in maxi
        }
        return maxi ; //maxi stores max diff b/w adjacent element in circular array
    }
};