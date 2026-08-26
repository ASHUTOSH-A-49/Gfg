class Solution {
  public:
    bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {
        // code here
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> dist(V,0);
        dist[0] = 0;
        for(int i = 0;i<V-1;i++){
            for(auto &e:edges){
                int u = e[0],v = e[1],w = e[2];
                if(dist[u]+w<dist[v]){
                    dist[v]   = dist[u]+w;
                }
            }
        }
        //one more cycle for negative cycle detection
        for(int i = 0;i<1;i++){
            for(auto e:edges){
                int u = e[0],v = e[1],w = e[2];
                if(dist[u]!=1e8 && dist[u]+w<dist[v]){
                    return true;
                }
            }
        }
        
        return false;
    }
};
