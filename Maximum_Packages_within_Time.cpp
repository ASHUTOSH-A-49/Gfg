class Solution {
  public:
    int maxPackages(vector<int>& arr, int totalTime) {
        // code here
        int maxpack = 0;
        int pack = 0;
        int l = 0;
        int n = arr.size();
        for(int i = 0;i<n;i++){
            pack+=arr[i];
            if(i>=totalTime){
                pack-=arr[l];
                l++;
            }
            maxpack = max(maxpack,pack);
        }
        return maxpack;
    }
};
