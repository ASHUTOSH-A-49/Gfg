class Solution {
  public:
    char nthCharacter(int n) {
        // code here
        int len = 1;
        long long count = 9;
        long long start = 1;
        while (n > len * count)
        {
            n -= len * count;
            len++;
            count *= 10;
            start *= 10;
        }
        long long number = start + (n - 1) / len;
        int digitIndex = (n - 1) % len;
        long long divisor = 1;
        for (int i = 0; i < len - digitIndex - 1; i++)
        {
            divisor *= 10;
        }
        int digit = (number / divisor) % 10;
        return '0' + digit;
    }
};
