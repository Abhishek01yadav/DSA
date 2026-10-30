class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto& e : edges)
            adj[e[0]].push_back({e[1], e[2]});

        const int INF = INT_MAX;
        // dist[node][streak], streak in 1..k
        vector<vector<int>> dist(n, vector<int>(k + 1, INF));

        // (distance, node, streak)
        priority_queue<tuple<int,int,int>,
                       vector<tuple<int,int,int>>,
                       greater<>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, s] = pq.top();
            pq.pop();
            if (d > dist[u][s]) continue;
            if (u == n - 1) return d;   // first pop of target is optimal

            for (auto& [v, wt] : adj[u]) {
                int ns = (labels[v] == labels[u]) ? s + 1 : 1;
                if (ns > k) continue;
                if (d + wt < dist[v][ns]) {
                    dist[v][ns] = d + wt;
                    pq.push({d + wt, v, ns});
                }
            }
        }
        return -1;
        
    }
};