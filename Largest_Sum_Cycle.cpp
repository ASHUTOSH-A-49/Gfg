class Solution {
  public:
  int DFSCycle(vector<int> & edge,vector<int> & visited,vector<int> & pathvis,int node){
      visited[node] = 1;
      pathvis[node] = 1;
      int next = edge[node];
      if(next == -1){
          pathvis[node] = 0;
          return -1;
      }
      if(!visited[next]){
          int cycle_start = DFSCycle(edge, visited, pathvis, next);
          if(cycle_start != -1) {
              pathvis[node] = 0;
              return cycle_start; 
          }
      } else if(pathvis[next]) {
          pathvis[node] = 0;
          return next;
      }
      pathvis[node] = 0;
      return -1;
  }
  int DFSCycleSum(vector<int> & edge,int node){
      int sum = node;
      int curr = edge[node];
      while(curr != node) {
          sum += curr;
          curr = edge[curr];
      }
      return sum;
  }
    int largestSumCycle(vector<int>& edge) {
        // code here
        int n = edge.size();
        vector<int> visited(n,0);
        vector<int> pathvis(n,0);
        int maxsum = -1;
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                int strt = DFSCycle(edge,visited,pathvis,i);
                if(strt!=-1){
                    int sum = DFSCycleSum(edge,strt);
                    maxsum = max(maxsum,sum);
                }
            }
        }
        if(maxsum==0) return -1;
        return maxsum;
        
    }
};
