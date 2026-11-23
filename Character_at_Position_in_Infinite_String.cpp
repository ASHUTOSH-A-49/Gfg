class Solution {
  public:
    char posInfinite(string &s, int pos) {
        // code here
        int n = s.length();
            long long len = n;
            int step = 1;
            while (len < pos)
            {
                len = 2 * len + step;
                step++;
            }
            while (step > 1)
            {
                long long prevLen = (len - (step - 1)) / 2;
                if (pos > prevLen && pos <= prevLen + step - 1)
                    return '$';

                if (pos <= prevLen)
                {
                    len = prevLen;
                }
                else
                {
                    pos = len - pos + 1;
                    len = prevLen;
                }

                step--;
            }
            return s[pos - 1];
    }
};
