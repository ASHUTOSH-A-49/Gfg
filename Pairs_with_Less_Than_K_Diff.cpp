class Solution {
  public:
  int UB(vector<int> & arr,int target){
      int l = 0,r = arr.size()-1,ans = -1;
      while(l<=r){
          int mid = l + (r-l)/2;
          if(arr[mid]>target){
              ans = mid;
              r= mid-1;
          }else{
              l = mid+1;
          }
      }
      return ans;
  }
    int countPairs(vector<int>& arr, int k) {
        // code here
        int pairs = 0;
        int n = arr.size();
        sort(arr.begin(),arr.end());
        for(int i =n-1;i>=0;i--){
            int diff = arr[i]-k;
            int idx = UB(arr,diff); 
            // cout<<idx<<" ";
            pairs+=(i-idx);
        }
        return pairs;
    }
};
