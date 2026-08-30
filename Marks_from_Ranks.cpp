class Solution {
  public:
    int BSinterv(vector<vector<int>> & interv, int target){
        int l = 0,r = interv.size()-1;vector<int> ans;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(interv[mid][2]>=target){
                r = mid-1;
                ans = interv[mid];
            }else l = mid+1;
        }
        int res = 0;
        if(ans.size()>0){
          int diff = ans[2]-target;  
          res = ans[1]-diff;
        }
        return res;
        
    }
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
        // code here
        int n = r.size();
        vector<vector<int>> interv(n); //left, right , rank
        int tot = 0;
        for(int i=0;i<n;i++){
            interv[i] = {l[i],r[i],tot+r[i]-l[i]+1};
            tot+=r[i]-l[i]+1;
        }
        vector<int> marks;
        for(int i:rank){
            int mark = BSinterv(interv,i);
            marks.push_back(mark);
        }
        return marks;
    }
};
