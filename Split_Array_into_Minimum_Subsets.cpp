class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        // code here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int sub = 1;
        for(int idx = 1;idx<n;idx++){
            if(arr[idx]-arr[idx-1]!=1){
                sub++;
            }
        }
        return sub;
    }
};
