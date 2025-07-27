class Solution {
public:
    // Helper function to get quiet value
    int getQuietIndexValue(vector<int>& quiet, int& index) {
        return quiet[index];
    }

    // DFS function to collect all richer people recursively
    void dfs(int node, unordered_map<int, vector<int>>& adj, vector<bool>& visited, vector<int>& collected) {
        visited[node] = true;
        collected.push_back(node);
        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, collected);
            }
        }
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        unordered_map<int, vector<int>> adj;

        // Build graph: poorer → richer
        for (auto& e : richer) {
            int u = e[0];
            int v = e[1];
            adj[v].push_back(u);
        }

        // Also include the node itself in adj list implicitly during DFS
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            vector<int> richerOrEqual;
            dfs(i, adj, visited, richerOrEqual);

            int minQuiet = INT_MAX;
            int quietestPerson = i;

            for (int person : richerOrEqual) {
                int val = getQuietIndexValue(quiet, person);
                if (val < minQuiet) {
                    minQuiet = val;
                    quietestPerson = person;
                }
            }

            ans[i] = quietestPerson;
        }

        return ans;
    }
};
