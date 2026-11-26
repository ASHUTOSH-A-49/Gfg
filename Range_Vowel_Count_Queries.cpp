class BIT {
public:
    vector<int> bit, arr;
    int n;

    BIT(vector<int>& nums) {
        n = nums.size();
        arr = nums;
        bit.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            add(i, arr[i]);
        }
    }
    void add(int idx, int val) {
        for (int i = idx + 1; i <= n; i += (i & -i)) {
            bit[i] += val;
        }
    }
    void update(int idx, int newVal) {
        int diff = newVal - arr[idx];
        arr[idx] = newVal;
        add(idx, diff);
    }

    int sum(int idx) {
        int ans = 0;
        for (int i = idx + 1; i > 0; i -= (i & -i)) {
            ans += bit[i];
        }
        return ans;
    }

    // Range sum for 0-based [l, r]
    int sumrange(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

class Solution {
  public:
    vector<int> countVowels(string &s, vector<vector<int>> &queries) {
        // code here
        int n = s.size();
        vector<int> arr(n,0);
        for(int i = 0;i<n;i++){
            char c = s[i];
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') arr[i]  = 1;
        }
        // for(int i:arr) cout<<i<<" ";
        // cout<<endl;
        BIT b(arr);
        // for(int i:b.bit) cout<<i<<" ";
        // cout<<endl;
        vector<int> ans;
        for(auto q:queries){
            int l = q[0],r= q[1];
            int res = b.sumrange(l,r);
            ans.push_back(res);
        }
        return ans;
        
    }
};
