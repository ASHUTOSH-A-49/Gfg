class Solution {
  public:
    int firstElementKTime(vector<int>& arr, int k) {
        // code here
        map<int,int> mp;
        for(int i:arr){
            mp[i]++;
            if(mp[i]==k) return i;
        }
        return -1;
    }
};
