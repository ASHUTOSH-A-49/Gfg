class Solution {
  public:
    
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {
        // code here
        vector<vector<pair<int,int>>>G(V);
        for(auto e:edges){
            int u = e[0],v = e[1],w = e[2];
            G[u].push_back({v,w});
            G[v].push_back({u,w});
        }
        
        vector<int> dist(V,INT_MAX);
        dist[src] = 0;
        queue<pair<int,int>> q;
        q.push({src,0});
        //do a simple BFS 
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int root = p.first;
            int d = p.second;
            for(auto p:G[root]){
                int node = p.first,d2 = p.second;
                if(d2+d < dist[node]){
                    dist[node] = d2+d;
                    q.push({node,d2+d});
                }
            }
        }
        return (dist[dest]==INT_MAX)?-1:dist[dest];
    }
};
