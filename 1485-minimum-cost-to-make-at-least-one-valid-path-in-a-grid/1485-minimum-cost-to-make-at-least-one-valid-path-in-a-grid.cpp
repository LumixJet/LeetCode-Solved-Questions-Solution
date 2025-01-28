class Solution {
public:
    int n,m;
    int dp[105][105]; //dp cell stores minimum cost to reach cell (x,y)
    bool isValid(int X, int Y) //checks cell is within grid boundary
    {
        return (X >= 0 && X < n && Y >= 0 && Y < m);
    }
    int minCost(vector<vector<int>>& grid) 
    {
        n = grid.size();
        m = grid[0].size();

        //represents direction right,left,down,up. each pair represent (row offset , column offset)
        vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        //basically dp table cell  stores min cost to reach till that respective cell
        memset(dp,0x3f,sizeof(dp)); //intialize cell with very large finite value

        //cell with 0 cost are processed first (front of deque) as we want to min the cost
        deque<pair<int,int>> dq; //so we first try cells which costs us 0 {i,j} of cell 

        dp[0][0] = 0; //as we start from the cell so it takes 0 cost to reach at that cell
        dq.push_front({0, 0}); //as we start with 1st cell {0,0}
        while(!dq.empty())
        {
            auto curr = dq.front();
            dq.pop_front();
            int x = curr.first; 
            int y = curr.second;
            
            for(int i=0;i<4;i++) //exploring all direction
            {
                int X = x + dir[i].first; //new x coordinate
                int Y = y + dir[i].second; //new y coordinate

                if(isValid(X,Y)) 
                {                 //add 1 if direction does not matches with current cell
                    int newCost = dp[x][y] + (grid[x][y] != i+1); // otherwise add 0

                    if(newCost < dp[X][Y]) //cond. to update new Cost in dp for next cell if
                    {                         //we found cheaper way to reach it 
                        dp[X][Y] = newCost;

                        if(grid[x][y] == i+1) //direction matches add cell to front of dq
                        {                        //to process it earlier 
                            dq.push_front({X,Y});
                        }
                        else //otherwise at back to process the cell later
                        {
                            dq.push_back({X,Y});
                        }
                    } //process cell whose direction does not match at last as they require cost
                } //so we process all cells which does not require cost ensures we reach end of 
            } //grid with minimum cost (minimum number of modification)
        }
        return dp[n-1][m-1]; //last cell of dp table stores min cost req to reach end
    }
};