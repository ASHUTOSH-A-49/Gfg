class Solution {
  public:
    int minComputation(vector<int> &files) {
        // code here
        priority_queue<int,vector<int>,greater<int>> pq;
        int n = files.size();
        if(n==1){
            return 0;
        }
        for(int i = 0;i<n;i++){
            pq.push(files[i]);
        }
        int ans = 0;
        while(!pq.empty()){
            int n1 = pq.top();
            pq.pop();
            if(pq.empty()) {
                break;
            }
            int n2 = pq.top();
            pq.pop();
            pq.push(n1+n2);
            ans+=n1+n2;
        }
        return ans;
    }
};
