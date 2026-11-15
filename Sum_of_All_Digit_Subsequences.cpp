class Solution {
  public:
  long long power(long long base, long long exp, long long mod) {
      long long res = 1;
      base %= mod;
      while (exp > 0) {
          if (exp % 2 == 1) res = (res * base) % mod;
          base = (base * base) % mod;
          exp /= 2;
      }
      return res;
  }
    int subsequenceSum(string &s) {
        // code here
        int n1 = s.size();
        vector<int> arr(n1);
        for(int i = 0;i<n1;i++){
            arr[i] = s[i]-'0';
        }
        long long mod = 1e9 + 7;
            long long n = arr.size();
            if (n == 0) return 0;

            long long digit_sum = 0;
            for (int x : arr) {
                digit_sum = (digit_sum + x) % mod;
            }

            long long ways = power(2, n - 1, mod);
            return (digit_sum * ways) % mod;
    }
};
