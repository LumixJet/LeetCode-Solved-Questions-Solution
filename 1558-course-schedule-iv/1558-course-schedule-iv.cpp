class Solution {
public:
    bool DFS(unordered_map<int, vector<int>> &adj, int u, int v, vector<bool> &visited)
    {
        visited[u] = true;
        if(u == v)
        {
            return true; //reached from u --> v
        }
        for(auto &ngbr : adj[u])
        {
            if(!visited[ngbr])
            {
                if(DFS(adj,ngbr,v,visited))
                {
                    return true;
                }
            }
        }
        return false;
    } 
    vector<bool> checkIfPrerequisite(int nCourse, vector<vector<int>>& preReq, vector<vector<int>>& queries) 
    {
        unordered_map<int, vector<int>> adj;

        for(auto &edge : preReq)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        int n = queries.size();
        vector<bool> result(n);
        for(int i=0;i<n;i++) //checking for each query weather u is v prerequisute 
        {                          //by calling DFS if yes then result is true else false
            int u = queries[i][0];
            int v = queries[i][1];

            vector<bool> visited(nCourse, false);
            result[i] = DFS(adj,u,v,visited); //we can use any DFS BFS as we just need to check
        }                                     //that weather from u node we can reach v node 
        return result;
    }
};