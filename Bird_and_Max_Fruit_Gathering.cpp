class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        // code here
        int maxf = 0;
        int f = 0;
        for(int i = 0;i<m-1;i++){
            arr.push_back(arr[i]);
        }
        
        //make circular array linear (above)
        int k = arr.size();
        int l = 0,r = 0;
        while(r<k){
            f+=arr[r];
            if(r-l+1>m){
                f-=arr[l];
                l++;
            }
            maxf = max(maxf,f);
            r++;
        }
        return maxf;
    }
};
