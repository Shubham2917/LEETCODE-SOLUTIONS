class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int,int>>>adj(n);
        int max_dist=0;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            if(online[u] and online[v]){
                adj[u].push_back({v,wt});
                max_dist = max(max_dist,wt);
            }
        }
        auto dijkastra = [&](long long mid){
            vector<long long> dist(n, LLONG_MAX);
            int src = 0, target = n-1;
            dist[src]=0;
            priority_queue<pair<long long, int>, vector<pair<long long, int>>,greater<>>pq;
            pq.push({0,src});
            while(!pq.empty()){
                auto it = pq.top();
                long long distance = it.first;
                int node = it.second;
                pq.pop();
                if(distance > dist[node]){
                    continue;
                }
                if(node == target){
                    return true;
                }
                for(auto [v,w]: adj[node]){
                    if(w<mid){
                        continue;
                    }
                    int new_dist = distance + w;
                    if(new_dist > k){
                        continue;
                    }
                    if(new_dist < dist[v]){
                        dist[v] = distance + w;
                        pq.push({dist[v], v});
                    }
                }
            }
            return false;
        };
        long long low=0, high = max_dist;
        long long ans = -1;
        while(low<=high){
            long long mid = low + (high - low)/2;
            if(dijkastra(mid)){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};