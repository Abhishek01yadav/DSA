class Solution {
public:
#define mod 1000000007
#define ll long long int 
vector<vector<ll>> dp = vector<vector<ll>>(1005, vector<ll>(1005, -1));
ll solve(int target,int k,int n){
    if(target==0) return 0;
    if(n==1) 
    {
        return (target>=1 && target<=k)? 1:0;
       
    }
    if(dp[target][n]!=-1) return dp[target][n];
    
    
ll sum=0;
   
    for(int i=1;i<=k;i++){
        if(target -i <0) break;
     sum=(sum %mod +   solve(target-i,k,n-1) % mod )%mod;
    }
 
   
   
    return  dp[target][n]=sum %mod;
}
    int numRollsToTarget(int n, int k, int target) {
        return solve(target,k,n);
        
    }
};