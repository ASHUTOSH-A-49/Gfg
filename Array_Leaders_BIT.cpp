class Solution {
  public:
    int bit[1000005];
    void add(int i,int delta,int maxelem){
        for(int idx = i;idx <= maxelem+1;idx+=idx&(-idx)){
            bit[idx] +=delta;
        }
    }
    int sum(int idx){
        int ans = 0;
        for(int i = idx;i>0;i-=i&(-i)){
            ans+=bit[i];
        }
        return ans;
    }
    vector<int> leaders(vector<int>& arr) {
        // code here
        // approach 1 
        // brute = O(n^2) - wont work
        
        // approach 2
        // using suff max  - O(N) TC , O(1) SC
    
        // approach 3 - BIT
        //very useful if it had FOLLOW UP  -  i.e. if update and find if an element is leader or not?
        int n = arr.size();
        int maxelem = 0;
        for(int i:arr) maxelem = max(maxelem,i);
        memset(bit, 0, (maxelem + 3) * sizeof(int));
        vector<int> ans;
        int tot = 0;
        for(int i = n-1;i>=0;i--){
            // cout<<sum(BIT,maxelem)<<" "<<sum(BIT,arr[i])<<endl;
            int val = arr[i]+1;
            int lead = tot-sum(val);
            if(lead<=0) ans.push_back(arr[i]);
            add(val,1,maxelem); //update
            tot++;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
