class Solution {
public:
vector<string> ans;
void solve(int idx,string &digits,string &temp,unordered_map<char,string>&mp){
    int n=digits.size();
    if(idx==n){
        ans.push_back(temp);
        
    }
    char ch=digits[idx];
    for(auto ele:mp[ch]){
        temp+=ele;
        solve(idx+1,digits,temp,mp);
        temp.pop_back();
        
    }
}
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
         mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        string temp="";
        int start=0;
        solve(start,digits,temp,mp);

return ans;
        
    }
};