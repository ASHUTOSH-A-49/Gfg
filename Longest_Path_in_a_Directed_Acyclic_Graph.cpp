class Solution {
  public:
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
        // code here
        vector<vector<pair<int,int>>> G(V);
        for(auto e:edges){
            int u = e[0],v = e[1],w = e[2];
            G[u].push_back({w,v});
        }
        vector<int> dist(V,INT_MIN);
        priority_queue<pair<int,int>> pq;
        dist[src] = 0;
        pq.push({0,src});
        while(!pq.empty()){
            auto[w1,node] = pq.top();
            pq.pop();
            for(auto [w2,i]:G[node]){
                if(w1+w2>dist[i]){
                    dist[i] = w1+w2;
                    pq.push({dist[i],i});
                }
            }
        }
        return dist;
        
    }
};
