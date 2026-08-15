class Solution {
  public:
    long long solve(int idx,long long mul,vector<int> & arr){
        int n = arr.size();
        if(idx==n) return 1e11;
        if(idx==n-1) {
            if(mul==1e11){
                return arr[idx];
            }
            return min(mul,mul*arr[idx]);
        }
        long long take = 1e11,skip = 1e11;
        if(mul==1e11){
            take = solve(idx+1,arr[idx],arr);
        }else{
            take = solve(idx+1,arr[idx]*mul,arr);
        }
        skip = solve(idx+1,mul,arr);
        return min(take,skip);
    }
    int minProd(vector<int>& arr) {
        // code here
        return solve(0,1e11,arr);
    }
};
