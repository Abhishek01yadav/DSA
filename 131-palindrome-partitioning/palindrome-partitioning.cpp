class Solution {
public:
bool ispallin(string s){
    int i=0,j=s.size()-1;
    while(i<=j){
        if(s[i]!=s[j]) return false ;
        i++;
        j--;
    }
    return true;
}
vector<vector<string>>res;
void solve(string &s,vector<string>&temp,int start){
    if(start==s.size()){
        res.push_back(temp);
        return ;
    }
    string pal_str;
    for(int i=start;i<s.size();i++){
        pal_str+=s[i];
        if(ispallin(pal_str)){
            temp.push_back(pal_str);
            solve(s,temp,i+1);
            temp.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        // vector<vector<string>>res;
         vector<string>temp;
        
         solve(s,temp,0);
         return res;


        
    }
};