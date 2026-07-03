 class Solution {
public:
    bool isValid(int mid, int n, const vector<vector<pair<int, int>>>& adj, const vector<bool>& online, long long k) {
        // Dijkstra to find shortest path from 0 to n-1 using only edges with weight >= mid
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<long long> dist(n, LLONG_MAX);
        
        if (online[0]) {
            pq.push({0, 0});
            dist[0] = 0;
        }
        
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            
            if (d > dist[u]) continue;
            if (u == n - 1) return d <= k;
            
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;
                
                if (weight >= mid && online[v]) {
                    if (dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                        pq.push({dist[v], v});
                    }
                }
            }
        }
        return dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        int low = 0, high = 0;
        
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            high = max(high, e[2]);
        }
        
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid == 0) { // Handle case where edge cost can be 0
                if (isValid(0, n, adj, online, k)) { ans = max(ans, 0); low = 1; }
                else break;
            } else if (isValid(mid, n, adj, online, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};