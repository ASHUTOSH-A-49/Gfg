class Solution {
  public:
    bool isPossible(int n, int m, string& s) {
        // code here
        int x = 0,y = 0;
        int min_x = 0, max_x = 0;
        int min_y = 0, max_y = 0;
        for(char c:s){
            if(c=='L') x--;
            if(c=='R') x++;
            if(c=='U') y--;
            if(c=='D') y++;
            
            min_x = min(min_x, x);
            max_x = max(max_x, x);
            min_y = min(min_y, y);
            max_y = max(max_y, y);
        }
        
        return (max_x - min_x + 1 <= m) && (max_y - min_y + 1 <= n);
    }
};
