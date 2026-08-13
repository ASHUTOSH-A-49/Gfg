class Solution {
  public:
   
    bool isPossible(vector<int>& arr, int s, int x) {
        // code here
        vector<long long> seq;
        int n=arr.size();
        long long sum=s;
        seq.push_back(s);
        for(int i=0;i<n;i++){
            long long next_num=sum+arr[i];
            if(next_num>x)break;
            seq.push_back(next_num);
            sum+=next_num;
        }
        for(int i=seq.size()-1;i>=0;i--){
            if(seq[i]<=x){
                x-=seq[i];
            }
        }
        return x==0;
        
        
    }
};
