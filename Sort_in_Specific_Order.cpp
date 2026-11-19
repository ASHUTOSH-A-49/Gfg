class Solution {
  public:
    void sortIt(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<int> ans(n);
        int l = 0,r = n-1;
        for(int i = n-1;i>=0;i--){
            if(arr[i]&1){
                ans[l] = arr[i];
                l++;
            }else{
                ans[r] = arr[i];
                r--;
            }
        }
        arr = ans;
        
    }
};
