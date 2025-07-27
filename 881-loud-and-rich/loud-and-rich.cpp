class Solution {
public:
    int getQuietIndexValue(vector<int>& quiet , int &index)
    {
        return quiet[index];  // simplified, same behavior
    }

    // DFS to collect all richer-or-equal people
    void dfs(int node, unordered_map<int , vector<int>>& adj, vector<bool>& visited, vector<int>& level)
    {
        visited[node] = true;
        level.push_back(node);

        for(auto neighbor : adj[node])
        {
            if(!visited[neighbor])
            {
                dfs(neighbor, adj, visited, level);
            }
        }
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) 
    {
        int n = quiet.size();
        unordered_map<int , vector<int>> adj(n);

        // building graph: poorer → richer
        for(auto &e : richer)
        {
            int u = e[0];
            int v = e[1];
            adj[v].push_back(u);  // direction fixed
        }

        // pushing the node itself in the adj list (optional here)
        for(int i = 0 ; i < n ; i++)
        {
            adj[i].push_back(i);
        }

        vector<int> ans;

        for(int i = 0 ; i < n ; i++)
        {
            vector<int> level;
            vector<bool> visited(n, false);

            // do DFS to collect all richer-or-equal people
            dfs(i, adj, visited, level);

            // find minimum quiet value
            int minVal = INT_MAX;
            int minPerson = i;

            for(int person : level)
            {
                int wt = getQuietIndexValue(quiet , person);
                if(wt < minVal)
                {
                    minVal = wt;
                    minPerson = person;
                }
            }

            ans.push_back(minPerson);
        }

        return ans;
    }
};
