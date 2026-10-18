class Solution {
public:
typedef long long ll;
ll mod=1e9+7;
vector<vector<ll>>PT;
int solve(vector<int>& nums){
    int n=nums.size();

    if(n<3) return 1;
   
    int root=nums[0];
    
    vector<int>leftarr;
    vector<int>rightarr;

    for(int i=1;i<n;i++){
        if(nums[i] >root){
            leftarr.push_back(nums[i]);
        }
        else{
            rightarr.push_back(nums[i]);
        }
    }

    ll x=solve(leftarr) %mod;
    ll y=solve(rightarr)%mod;

    ll z=PT[n-1][leftarr.size()] %mod;

    return ((x*y)%mod *z)%mod;

}
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        PT.resize(n+1);

        for(int i=0;i<=n;i++){
            PT[i]=vector<ll>(i+1,1);
            for(int j=1;j<i;j++){
                PT[i][j]=(PT[i-1][j]+PT[i-1][j-1])%mod;
            }
        }

        ll ans=solve(nums);
        return ans-1;

        
    }
};