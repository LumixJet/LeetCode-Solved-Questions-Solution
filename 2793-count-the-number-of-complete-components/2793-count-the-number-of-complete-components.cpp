class Solution {
public:
    void dfs(int i, unordered_map<int,vector<int>> &adj, vector<bool> &vis, int &e, int &v)
    {
        vis[i] = true; //mark that node as true
        v++; //count the vertex
        e += adj[i].size(); //associated to that vertex count number of edges from adjacency list of graph

        for(int ngbr : adj[i]) //now we find all neighbour of current vertex 
        {
            if(!vis[ngbr]) //if that neighbour vertex is not visited we call DFS over that neighbour vertex
            {
                dfs(ngbr,adj,vis,e,v);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) 
    {
        unordered_map<int,vector<int>> adj; //forming a graph
        int res = 0; //variable to store total number of connected component present 

        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n,false); //bool vector to mark which nodes are visited earlier

        for(int i=0;i<n;i++) //traversing all the vertex present in graph
        {
            if(vis[i] == true) //if we get a vertex which is already visited then we continue to other vertex
            {
                continue;
            }

            int e = 0; //variable to store number of edges present 
            int v = 0; //variable to store number of vertex present

            dfs(i,adj,vis,e,v); //call DFS on the vertex which is not visited

            if((v*(v-1) / 2) == e/2) //after counting number of vertex and edges present in component of graph
            {                                               //we check the condition if it is getting satisfied

                res ++; //means that component of graph is complete connected component of graph 
            }
        }
        return res; //at last we return total number of connected component present in graph
    }
};