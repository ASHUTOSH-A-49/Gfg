class Solution {
  public:
    int minMoves(vector<int>& arr) {
        // code here
        int n = arr.size();
        int count[n + 1] = {0};
        for (int x : arr) {
            if (count[x - 1]!= 0) {
                count[x] = count[x - 1] + 1;
            } else {
                count[x] = 1;
            }
        }

        int longest = 0;
        for (int i = 0; i <= n; ++i) {
            longest = max(longest, count[i]);
        }
        return n - longest;
    }
};
