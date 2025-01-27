class Solution {
public:
    int countServers(vector<vector<int>>& grid) 
    {
      int m = grid.size();
      int n = grid[0].size();

        vector<int> cRow(m, 0); //count server in row where its index denotes row and value represent count
        vector<int> cCols(n, 0); //count server in column where its index denotes column and value represent counts

        for(int i=0;i<m;i++) //pre-compute number of 1's present in each rows and columns 
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    cRow[i] = cRow[i] + 1; //store in cRow array at respective index 
                    cCols[j] = cCols[j] + 1; //store in cCols array at respective index
                } 
            }
        }

        int res = 0;
            
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                //if we get 1 in cell of grid and if there is 1 present in that cell row or column we do res ++
                if(grid[i][j] == 1 && (cRow[i] > 1 || cCols[j] > 1)) //that means that server can communicate 
                {
                    res ++ ;
                }
            }
        }

        return res; //returning total such server that can communicate with each other
    }
};