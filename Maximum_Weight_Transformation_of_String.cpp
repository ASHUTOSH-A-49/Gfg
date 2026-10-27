class Solution {
  public:
  int dp[100005][2][2]; 

      int solve(int i, string &s, int prev_char, int is_paired) {
          if (i == s.size()) {
              return is_paired ? 0 : 1; 
          }

          if (dp[i][prev_char][is_paired] != -1) {
              return dp[i][prev_char][is_paired];
          }

          int orig_char = s[i] - 'A';
          int ans = -1e9;
          for (int c = 0; c <= 1; ++c) {
              int toggle_cost = (c == orig_char) ? 0 : 1;
              if (!is_paired && c != prev_char) {
                  ans = max(ans, 4 - toggle_cost + solve(i + 1, s, c, 1));
              }
              int prev_contribution = is_paired ? 0 : 1;
              ans = max(ans, prev_contribution - toggle_cost + solve(i + 1, s, c, 0));
          }

          return dp[i][prev_char][is_paired] = ans;
      }

      int getMaxWeight(string &s) {
          int n = s.size();
          if (n == 0) return 0;
          if (n == 1) return 1; 
          for (int i = 0; i <= n; ++i) {
              for (int j = 0; j < 2; ++j) {
                  for (int k = 0; k < 2; ++k) {
                      dp[i][j][k] = -1;
                  }
              }
          }

          int orig_first = s[0] - 'A';
          int ans = -1e9;
          for (int c = 0; c <= 1; ++c) {
              int toggle_cost = (c == orig_first) ? 0 : 1;
              ans = max(ans, -toggle_cost + solve(1, s, c, 0));
          }

          return ans;
      }
};
