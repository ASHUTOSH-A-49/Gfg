//KADANE + SLIDING WINDOW

class Solution {
  public:
    int maxSumWithK(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<int> preMax(n);
        preMax[0] = arr[0];
        int currMax = arr[0];
        for (int i = 1; i < n; i++) {
            currMax = max(arr[i], currMax + arr[i]);
            preMax[i] = currMax;
        }
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        int res = sum;
        for (int i = k; i < n; i++) {
            sum = sum + arr[i] - arr[i-k];
            res = max(res, sum);
            res = max(res, sum + preMax[i-k]);
        }
        
        return res;
    }
};
