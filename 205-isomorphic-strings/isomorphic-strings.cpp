class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() !=t.size()) return false;
        int i=0,j=0;
        unordered_map<int,int>mp,mpp;
        while(i<s.size()){
           if(mp.find(s[i])!=mp.end() && mp[s[i]]!=t[j]){
        
          return false;
           }
          mp[s[i]]=t[j];
          i++;j++;


        }
        i=0,j=0;

        while(i<t.size()){
           if(mpp.find(t[i])!=mpp.end() && mpp[t[i]]!=s[j]){
        
          return false;
           }
          mpp[t[i]]=s[j];
          i++;j++;


        }
       return true; 
    }
};