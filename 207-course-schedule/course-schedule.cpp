class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        unordered_map<int , vector<int>> adj;
        vector<int> indegree(numCourses , 0);
        for(auto &e : prerequisites)
        {
            int u = e[0];
            int v = e[1];
            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;
        int count=0;
        for(int i=0 ; i<numCourses ; i++)
        {
            if(indegree[i] == 0)
            {
                count++;
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
                    count++;
                    q.push(v);
                }
            }
        }

        if(count == numCourses)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};