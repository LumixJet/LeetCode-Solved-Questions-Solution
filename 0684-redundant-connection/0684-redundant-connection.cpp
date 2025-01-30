class Solution {
public:
    bool DFS(unordered_map<int, vector<int>> &adj, int u, int v, vector<bool> &visited)
    {

        if(u == v) //if u and v both becomes same that means we found a cycle
        {
            return true;
        }

        visited[u] = true; //mark u as true as we are going to start DFS from this vertex of graph

        for(auto &ngbr : adj[u]) //traverses all the adjacent vertices of graph 
        {
            if(!visited[ngbr] && DFS(adj,ngbr,v,visited)) //if vertex is not visited call DFS on  newighbour vertex now
            {
                return true; //if at any moment DFS return true that means we get the cycle between the graph
            }
        }
        return false; //if by traversing all edges we dont get cycle we return false
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n = edges.size();

        unordered_map<int, vector<int>> adj;

        for(int i=0;i<n;i++) //make graph edges one by one by traversing the array which is given to us
        {
            int u = edges[i][0]; 
            int v = edges[i][1];

            vector<bool>visited(n+1,false);

            if(adj.find(u) != adj.end() && adj.find(v) != adj.end()) //if both vertex are already present before hand
            {
                if(DFS(adj,u,v,visited)) //then we check weather there is cycle present between them or not
                {
                    return edges[i]; //if DFS returns true we return the edge which is making cycle in graph
                }
            }
            //if any one of vertex is not present in graph then we make edge between the both vertex 
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {}; //if we dont find any cycle between edge than we return null edge 
    }
};