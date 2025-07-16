class Solution {
public:
    bool dfs(int u, vector<int> &visited, unordered_map<int, vector<int>> &adj, stack<int> &st) {
        visited[u] = 1;  // mark as visiting

        for (int &v : adj[u]) {
            if (visited[v] == 1) return false; // cycle detected
            if (visited[v] == 0) {
                if (!dfs(v, visited, adj, st)) return false;
            }
        }

        visited[u] = 2;  // mark as visited
        st.push(u);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        unordered_map<int, vector<int>> adj;
        for (auto &e : prerequisites) {
            int u = e[0];
            int v = e[1];
            adj[v].push_back(u); // course `v` is a prerequisite of `u`
        }

        vector<int> visited(numCourses, 0); // 0=unvisited, 1=visiting, 2=visited
        stack<int> st;

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (!dfs(i, visited, adj, st)) {
                    return {}; // cycle found
                }
            }
        }

        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        return res;
    }
};
