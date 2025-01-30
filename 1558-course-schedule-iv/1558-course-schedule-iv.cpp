class Solution {
public:
    vector<bool> checkIfPrerequisite(int nCourses, vector<vector<int>>& preReq, vector<vector<int>>& queries) 
    {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(nCourses, 0); //vector to count indegree of vertex in graph 

        for(auto &edge : preReq)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            indegree[v] ++; //as edge is going from u to v (u-->v) so we increase indegree of v
        }

        queue<int>q; //to store node which gets indegree 0 we store them to process its neighbour
        for(int i=0;i<nCourses;i++)
        {
            if(indegree[i] == 0) //if indegree of vertex becomes 0 we push to queue
            {
                q.push(i);
            }
        }

        unordered_map<int, unordered_set<int>> mp; //to store pre-requisites of all vertex of graph
        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto &ngbr : adj[node]) //take neighbour of current node
            {
                mp[ngbr].insert(node); //as neighbour node pre-requisite will be current node

                for(auto &preq : mp[node]) //check for pre-requisites of current nodes which are present in 
                {                             //mp as that will too be pre-requisites of neighbour node
                    mp[ngbr].insert(preq);
                }
                indegree[ngbr] --; //decrease neighbour node indegree by 1 as current node is processed 

                if(indegree[ngbr] == 0) //if indegree of neighbour of node becomes 0 
                {
                    q.push(ngbr); //we push it to queue
                }
            }
        }

        int Q = queries.size();
        vector<bool>  res(Q, false); //vector to store result of all queries 

        for(int i=0;i<Q;i++) //traverse queries given to us 
        {
            int src = queries[i][0]; //find 1st node which will be source node 
            int dest = queries[i][1]; //find 2nd node which will be destination node 

            bool reach = mp[dest].contains(src); //if inside destination index of mp source node is 
            res[i] = reach; //present that means source is pre-requisite of destination so we mark it true
        }

        return res;

    }
};