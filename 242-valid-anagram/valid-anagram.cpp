class Solution {
public:
    bool isAnagram(string s, string t) {
        int m=s.size(),n=t.size();
        if(m!=n) return false;
        unordered_map<char,int>mp;
      for(auto ele:s){
        mp[ele]++;
      }

      for(auto ele:t){
        if(mp.find(ele)!=mp.end()){
            mp[ele]--;
            if(mp[ele]==0) mp.erase(ele);
        }
      }
      return mp.size()==0;



    



         









        
    }
};