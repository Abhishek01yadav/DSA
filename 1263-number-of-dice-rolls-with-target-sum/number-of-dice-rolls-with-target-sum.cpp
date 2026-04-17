class Solution {
public:
#define mod 1000000007
#define ll long long int 
//vector<vector<ll>> dp = vector<vector<ll>>(1005, vector<ll>(1005, -1));// note 2d dp kyuki sttate of dp n and target hai.
// ll solve(int target,int k,int n){
//     if(target==0) return 0;
//     if(n==1)   return (target>=1 && target<=k)? 1:0; 
//     if(dp[target][n]!=-1) return dp[target][n];
//     ll sum=0;

//     for(int i=1;i<=k;i++)
//     {
//         if(target -i <0) break;
//      sum=(sum %mod +   solve(target-i,k,n-1) % mod )%mod;
//     }

//     return  dp[target][n]=sum %mod;
// }
// ll f(int n,int k,int t){
//     if(n==0 and t==0) return 1;
//     if(n==0) return 0;
//     ll sum=0;
//     if (dp[t][n]!=-1) return dp[t][n];
//     for(int i=1;i<=k;i++){
//         if(t-i < 0) break;
//         sum= (sum %mod + f(n-1,k,t-i)%mod ) %mod;

//     }
//     return  dp[t][n]=sum %mod; 



// }

ll fbu(int n,int k,int t){
    vector<vector<ll>>dp= vector<vector<ll>>(1005,vector<ll>(1005,0));
    dp[0][0]=1;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=t;j++){
            for(int r=1;r<=k;r++){
                if(j-r <0) break;
                dp[i][j]+=(dp[i-1][j-r])%mod;
            }
        }
    }
    return dp[n][t] % mod;



}


    int numRollsToTarget(int n, int k, int target) {
        return fbu(n,k,target);
        
    }
};