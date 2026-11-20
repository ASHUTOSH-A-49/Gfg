class Solution {
  public:
    int minFlips(string &s) {
        // code here
        int n = s.size(), count = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] - '0' != i % 2) count++;
            }
            return min(count, n - count);
    }
};
