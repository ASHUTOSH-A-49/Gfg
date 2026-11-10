class Solution {
  public:
    bool checkWithinK(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        map<int,int> mp;
        for(int i = 0;i<n;i++){
            if(mp.count(arr[i])>0){
                if(i-mp[arr[i]]<=k) return true;
            }
            mp[arr[i]] = i;
        }
        return false;
    }
};
