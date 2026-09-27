class Solution {
public:
bool ispalli(string s){
    int i=0,j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
void f(int idx,string  s,vector<vector<string>>&ans,vector<string>&ds){
    int n=s.size();
    if(idx==n){
        ans.push_back(ds);
        return ;
    }

    for(int i=idx;i<n;i++ ){
        string str=s.substr(idx,i-idx+1);
        if(ispalli(str)){
            ds.push_back(str); 
            f(i+1,s,ans,ds);
            ds.pop_back();
        }


    }

}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>ds;
        f(0,s,ans,ds);
        return  ans;
        
    }
};