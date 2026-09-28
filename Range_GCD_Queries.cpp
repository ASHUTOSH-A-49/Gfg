class SegTree{
    int n;
    vector<int> Stree;
    void BuildTree(vector<int> & arr,int idx,int l,int r){
        if(l==r){
            //BASE CASE
            Stree[idx] = arr[r];
            return;
        }
        int mid = (l+r)/2;
        BuildTree(arr,2*idx+1,l,mid); //go left node -recursion
        BuildTree(arr,2*idx+2,mid+1,r); //go right node -recursion
        Stree[idx] = gcd(Stree[2*idx+1] , Stree[2*idx+2]); //building tree
    }

    int RangeGCDQuery(int idx,int start,int end,int l,int r){
        // idx = idx in seg tree array i.e. Stree
        // start, end = target range of which range sum we want fixed in recursive calls
        // l,r = range of nodes in seg tree , changes in recursive calls
        if(r<start || end<l){
            return 0; //BASE CASE - when nothing is in range
        }
        if(l>=start && r<=end){
            return Stree[idx];// BASE CASE  -  when both l and r are inside range
        }
        int mid = (l+r)/2;
        //recursion calls to left and right nodes 
        return gcd(RangeGCDQuery(2*idx+1,start,end,l,mid), RangeGCDQuery(2*idx+2,start,end,mid+1,r));
    }
    void updateGCDQuery(int idx,int val,int i,int l,int r){
        //idx = idx of nums at which needs to update value to val
        //i = idx of seg tree
        //l,r - range in segment tree nodes
        if(l==r){
            Stree[i] = val; 
            return;
        }
        int mid = (l+r)/2;
        if(idx<=mid){
            //go left
            updateGCDQuery(idx,val,2*i+1,l,mid);
        }else{
            //go right
            updateGCDQuery(idx,val,2*i+2,mid+1,r);
        }
        //update
        Stree[i] = gcd(Stree[2*i+1] , Stree[2*i+2]);
    }

    public:
    SegTree(vector<int> & nums){
        n = nums.size();
        Stree.assign(4*n,0);
        if(n>0) BuildTree(nums,0,0,n-1);
    }
    void updateQuery(int idx,int val){
        updateGCDQuery(idx,val,0,0,n-1);
    }
    void printST(){
        for(int i:Stree){
            cout<<i<<" ";
            
        }
        cout<<endl;
    }
    int getRangeGCD(int start,int end){
        return RangeGCDQuery(0,start,end,0,n-1);
    }
};


class Solution {
  public:
    vector<int> processQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        SegTree st(arr);
        vector<int> ans;
        for(auto q:queries){
            int t = q[0];
            if(t==0){
                ans.push_back(st.getRangeGCD(q[1],q[2]));
            }else{
                st.updateQuery(q[1],q[2]);
            }
        }
        return ans;
        
        
    }
};
