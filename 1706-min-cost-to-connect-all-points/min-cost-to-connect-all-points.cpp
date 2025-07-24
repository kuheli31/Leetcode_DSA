class Solution {
public:
    typedef pair<int , int> p;

    int prim(int &V , vector<vector<p>> &adj)
    {
        vector<bool> inMST(V , false);
        int sum = 0;
        priority_queue<p , vector<p> , greater<p>> pq;
        pq.push({0 , 0}); // (weight, node)

        while (!pq.empty())
        {
            auto [wt, node] = pq.top();
            pq.pop();

            if (inMST[node]) continue;

            inMST[node] = true;
            sum += wt;

            for (auto &it : adj[node])
            {
                int v = it.first;
                int vwt = it.second;

                if (!inMST[v])
                    pq.push({vwt , v});
            }
        }
        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int V = points.size();
        vector<vector<p>> adj(V);

        for (int i = 0; i < V; i++)
        {
            for (int j = i + 1; j < V; j++)
            {
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x1 - x2) + abs(y1 - y2);

                adj[i].push_back({j , dist});
                adj[j].push_back({i , dist});
            }
        }

        return prim(V , adj);
    }
};
