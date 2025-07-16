class Solution {
public:
    void bfs(unordered_map<int , vector<int>>&adj , int numCourses , vector<int>&res , vector<int> &indegree)
    {
        //fill the queue
        queue<int> q;
        for(int i=0 ; i<numCourses ; i++)
        {
            if(indegree[i] == 0)
            {
                res.push_back(i);
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            for(auto &v : adj[u])
            {
                indegree[v]--;
                if(indegree[v] == 0)
                {
                    res.push_back(v);
                    q.push(v);
                }
            }
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        unordered_map<int , vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for(auto &e : prerequisites)
        {
            int u = e[0];
            int v = e[1];
            adj[v].push_back(u);
            indegree[u]++;
        }

        vector<int> res;
        bfs(adj , numCourses , res , indegree);
        if(res.size() == numCourses)
        {
            return res;
        }
        else
        {
            return {};
        }
    }
};