class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> arr; //used to store all the elements present in array 
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                arr.push_back(grid[i][j]); //storing all the elements present in grid in array
            }
        }

        int nums = arr.size();  //size of array in which we have stored elements of grid
        sort(arr.begin(),arr.end()); //sorting array in ascending order  

        int indi = nums/2; //also taking the index of a number which is target number. 
        int target = arr[nums/2]; //target number will be number which we will make all number equal to that
        int ops = 0; //will count total number of operation which is required to make Uni-valud grid

        for(int i=0;i<nums;i++) //tarversing to the vector array which has all number which were present in grid
        {
            if(i != indi) //if i is not same as indi that means that number we have to make equal to target 
            {
                int res = abs(target - arr[i]); //we first subtract target with current number 
                if(res % x == 0) //there difference modulo with x if it is 0 that means we can make current number equal 
                {                    //to target value. So we count total number of operation which is required to make
                    ops += res/x; //current number equal to target value
                }
                else //if any time we found res modulo with x is not equal to 0 that means that number cant be converted to 
                {                   //target value making grid not uni-value therefore we return -1 representing that it is
                    return -1;  //impossible to make given grid uni-value
                }
            }
        }
        return ops; //return ops which is minimum number of operation required to make grid uni-valued
    }
};