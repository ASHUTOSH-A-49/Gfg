class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        // approach 1 
        // brute = O(n^2) - wont work
        
        // approach 2
        // using suff max  - O(N) TC , O(1) SC
        int n = arr.size();
        vector<int> suff(n);
        suff[n-1] = arr[n-1];
        for(int i = n-2;i>=0;i--){
            suff[i] = max(suff[i+1],arr[i]);
        }
        vector<int> ans;
        for(int i = n-1;i>=0;i--){
            int lead  = suff[i];
            if(arr[i]>=lead) ans.push_back(arr[i]);
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
