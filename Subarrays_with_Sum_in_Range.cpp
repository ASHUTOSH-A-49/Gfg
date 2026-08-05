class Solution {
  public:
    int subarrSumAtMostK(vector<int> & arr,int k){
        int n = arr.size();
        int l = 0,r = 0,cnt = 0,sum = 0;
        while(r<n){
            sum+=arr[r];
            while(sum>k && l<=r){
                sum-=arr[l];
                l++;
            }
            cnt+=r-l+1;
            r++;
        }
        return cnt;
        
    }
    int countSubarray(vector<int>& arr, int l, int r) {
        // code here
        return subarrSumAtMostK(arr,r) - subarrSumAtMostK(arr,l-1);
    }
};
