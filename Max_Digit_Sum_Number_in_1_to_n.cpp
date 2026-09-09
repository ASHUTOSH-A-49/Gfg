class Solution {
  public:
    int getDigitSum(int num) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            return sum;
        }
    int findMax(int n) {
        // code Here
        string s = to_string(n);
                int len = s.length();

                int maxAns = n;
                int maxSum = getDigitSum(n);

                for (int i = 0; i < len; i++) {
                    if (s[i] == '0') continue;

                    string candidateStr = s;
                    candidateStr[i]--;
                    for (int j = i + 1; j < len; j++) {
                        candidateStr[j] = '9';
                    }

                    int candidateNum = stoi(candidateStr);
                    int candidateSum = getDigitSum(candidateNum);

                    if (candidateSum > maxSum) {
                        maxSum = candidateSum;
                        maxAns = candidateNum;
                    } else if (candidateSum == maxSum) {
                        maxAns = max(maxAns, candidateNum);
                    }
                }

                return maxAns;
        
    }
};
