class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        // code here
        int ans=0;
        int n= arr.size();
        for (int i= 0;i<n;i++){
            long long occur= (long long) (n-i) *(i+1);
            if((occur%2 )== 1) ans= ans^arr[i];

        }
        return ans;
    }
};
