class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        // code here
            int n = arr.size(), res = 0;
            unordered_map<int, int> prefIdx;
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum = ((sum + arr[i]) % k + k) % k;
                if (sum == 0)
                    res = i + 1;
                else if (prefIdx.find(sum) != prefIdx.end()) {
                    res = max(res, i - prefIdx[sum]);
                }
                else {
                    prefIdx[sum] = i;
                }
            }
            return res;
    }
};
