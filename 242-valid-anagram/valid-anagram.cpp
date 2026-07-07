class Solution {
public:
    bool isAnagram(string s, string t) {
       unordered_map<char,int>mp;
       for(auto ele:s){
        mp[ele]++;
       }
    
    for(int i=0;i<t.size();i++){
        mp[t[i]]--;
        if(mp[t[i]]==0) mp.erase(t[i]);

    }
    if(mp.size()==0) return true;
    return false;
    }
};