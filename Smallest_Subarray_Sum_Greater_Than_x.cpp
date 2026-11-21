class Solution {
  public:
    int smallestSubWithSum(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        int l = 0,r = 0;
        int minsiz = n+1,sum = 0;
        while(r<n){
            while(r<n && sum<=x){
                sum+=arr[r];
                r++;
            }
            while(l<=r && sum>x){
                sum-=arr[l];
                minsiz = min(minsiz,r-l);
                l++;
            }
        }
        return (minsiz==n+1)?0:minsiz;
    }
};
