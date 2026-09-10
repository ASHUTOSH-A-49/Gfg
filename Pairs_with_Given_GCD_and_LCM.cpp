class Solution {
  public:
    int pairCount(int x, int y) {
        // code here
        int n = 0, res = 0;
            if (y % x == 0)
                n = y / x;
            if (n == 1)
                res = 1;
            for (int i = 1; i <= sqrt(n); i++)
            {
                if (n % i == 0)
                {
                    int j = n / i;
                    if (i != j && __gcd(x * i, x * j) == x)
                        res += 2;
                }
            }

            return res;
    }
};
