

class Solution {
  public:
    
    vector<vector<int>> levelSort(vector<int>& arr) {
        // code here
        int siz = arr.size();
        queue<int> q;
        q.push(0);
        vector<vector<int>> ans;
        while(!q.empty()){
            int n = q.size();
            vector<int> level;
            for(int i = 0;i<n;i++){
                int idx = q.front();
                level.push_back(arr[idx]);
                q.pop();
                if(2*idx+1 < siz) q.push(2*idx+1);
                if(2*idx+2 < siz) q.push(2*idx+2);
            }
            sort(level.begin(),level.end());
            ans.push_back(level);
        }
        return ans;
        
    }
};
