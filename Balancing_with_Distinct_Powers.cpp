class Solution {
  public:
    bool balancePan(int a, int b) {
        // code here
        if (a == 1) {
                    return (b == 0 || b == 1);
                }

                while (b > 0) {
                    int remainder = b % a;
                    if (remainder == 0) {
                        b /= a;
                    } else if (remainder == 1) {
                        b = (b - 1) / a;
                    } else if (remainder == a - 1) {
                        b = (b + 1) / a;
                    } else {
                        return false;
                    }
                }

                return true;
        
        
    }
};
