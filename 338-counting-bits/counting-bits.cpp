class Solution {
public:
    vector<int> countBits(int n) {
       vector< int >ans(n+1);
        int temp;
        int  countones=0;
        for(int k=0;k<=n;k++){
         int an=__builtin_popcount(k);
           
               
           ans[k]=an;

            
        }
        return ans;
        
    }
};