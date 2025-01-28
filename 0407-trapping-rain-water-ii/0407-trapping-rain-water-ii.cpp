class Solution {
public:
    typedef pair<int, pair<int, int>> pp; //made pair of {h, {i,j}};
    int trapRainWater(vector<vector<int>>& height) 
    {
        if(height.empty() || height[0].empty()) //if row or column is empty then its base case 
        {                                       //no watter can get stored as water can be hold 
            return 0;
        }

        int n = height.size();
        int m = height[0].size();

        priority_queue<pp, vector<pp>, greater<>> pq; // min heap stores {h,{i,j}} to process boundary cells heights in ascending order
        vector<vector<bool>> visited(n, vector<bool> (m, false)); //to mark what all cells are visited in in height matrix

        for(int i=0;i<n;i++) //storing value in first and last column cell of height array as boundary cells can not store water 
        {
            if(!visited[i][0])
            {
                pq.push({height[i][0], {i,0}}); //to store first column cell of height matrix
                visited[i][0] = true;
            }
            if(!visited[i][m-1])
            {
                pq.push({height[i][m-1],{i,m-1}}); //to store last column cell of height matrix
                visited[i][m-1] = true;
            }
        }
        for(int i=0;i<m;i++) //storing the first and last row cell of height array as boundary cells can not store water
        {
            if(!visited[0][i])
            {
                pq.push({height[0][i], {0,i}}); //to store first row cell of height matrix
                visited[0][i] = true;
            }
            if(!visited[n-1][i]) 
            {
                pq.push({height[n-1][i],{n-1,i}}); //to store last row cell of height matrix
                visited[n-1][i] = true;
            }
        }

        int tappedWater = 0; 
        vector<pair<int, int>> direc= {{0,1},{0,-1},{-1,0},{1,0}}; //all 4 direction right, left, top and bottom

        while(!pq.empty())
        {
            auto [h,cell] = pq.top();
            pq.pop();

            int x = cell.first; //current cell x coordinate
            int y = cell.second; //current cell y coordinate

            for(auto[dx,dy] : direc) //check for all possible directions of its neighbour array
            {
                int nx = x + dx; //neighbor row x coordinate
                int ny = y + dy; //neighbor row y coordinate

                //check out of bound condition and also check weather cell is visited or not
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny])
                {
                    visited[nx][ny] = true; //marked cell as visited and we store amount of water that can be stored in curr
                    tappedWater += max(h-height[nx][ny], 0); //cell if it gives +ve then that stores otherwise it stores 0 means 
                                                                //water cannot be guarded 
                    pq.push({max(h,height[nx][ny]), {nx,ny}}); //store next cell in pq so that it can check for its neighbour
                }   //we take max(h,height[nx][ny]) because height of max will be there to guard water of its neighbour cell
            }
        }
        return tappedWater;
    }
};