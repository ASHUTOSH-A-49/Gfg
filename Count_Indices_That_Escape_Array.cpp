class Solution {
  public:
    int goodIndices(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> reach(n,0);
        for(int i = 0;i<n;i++){
            bool flag = false;
            int idx = i;
            queue<int> qidx;
            reach[i] = 2;
            qidx.push(i);
            while(true){
                if(arr[idx]==0) break;
                int nextidx = idx+arr[idx];
                if(nextidx<0 || nextidx>=n){
                    flag = true;
                    break;
                }else if(reach[nextidx]==1){
                    flag = true;
                    break;
                }else if(reach[nextidx]==-1 || reach[nextidx]==2){
                    break;
                }else{
                    idx = nextidx;
                    qidx.push(nextidx);
                    reach[nextidx] = 2;
                }
            }
            while(!qidx.empty()){
                int i = qidx.front();
                qidx.pop();
                reach[i] = (flag)?1:-1;
            }
        }
        int cnt = 0;
        for(int i:reach){
            if(i==1) cnt++;
        }
        return cnt;
    }
};
