class Solution {
public:


int lcs(int i,int j,string &s,string &t,vector<vector<int>>&dp){

    if(i>=s.size() || j>=t.size()) return 0;

    if(dp[i][j] !=-1) return dp[i][j];
//match
    if(s[i]==t[j])  return  dp[i][j]=1+lcs(i+1,j+1,s,t,dp);
    
    //not match

    return dp[i][j]= max(lcs(i+1,j,s,t,dp),lcs(i,j+1,s,t,dp));


}

    int longestPalindromeSubseq(string s) {
        vector<vector<int>>dp(1000,vector<int>(1000,-1));
    string t=s;
    reverse(s.begin(),s.end());
    int len=lcs(0,0,s,t,dp);
    return len;

    
    }
};       