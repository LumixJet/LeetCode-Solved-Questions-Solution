class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) 
    {
        long long fRowSum = accumulate(begin(grid[0]), end(grid[0]), 0LL); //finding sum of first row of grid
        long long sRowRemainSum = 0;

        long long minSumR2 = LONG_LONG_MAX;

        for(int j=0;j<grid[0].size();j++) //represents all possible stratergy which robot 1 can make
        {                                //to minimize total score of Robot 2

           fRowSum -= grid[0][j]; //robot 1 stratergy

           long long bestR2 = max(fRowSum,sRowRemainSum); //best Robot 2 can make for itself

            minSumR2 = min(minSumR2, bestR2); //out of all best of Robot2 minimum part will be finalized

           sRowRemainSum += grid[1][j]; //if Robot 1 takes turn to below from 1st row and 2nd column then
        }                              //then for Robot 2 will have sRemainSum (some value in second row) available for it.

        return minSumR2; //out of all best for robot 2, robot 2 will get min possible as Robot 1 make 
    }                   //that only happen as it wants to minimumize robot 2 score 
};