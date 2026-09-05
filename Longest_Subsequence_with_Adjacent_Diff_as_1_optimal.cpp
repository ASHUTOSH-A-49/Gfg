class Solution {
  public:
    int longestSubseq(vector<int>& arr) {
        // code here
        unordered_map<int, int> dp;
            int maxlen = 0;

            for (int x : arr) {
                int left = dp.count(x - 1) ? dp[x - 1] : 0;
                int right = dp.count(x + 1) ? dp[x + 1] : 0;

                dp[x] = max(left, right) + 1;
                maxlen = max(maxlen, dp[x]);
            }

            return maxlen;
    }
};
