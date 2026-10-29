class Solution {
public:
typedef pair<char,int>P;
    string frequencySort(string s) {
        string result="";
        vector<P>v(123);
        
        for(auto &ch:s){
            int freq=v[ch].second;
            v[ch]={ch,freq+1};
        }

       auto lambda=[&](P p1,P p2){
        return p1.second>p2.second;
       };

       sort(v.begin(),v.end(),lambda);

      for(auto &p:v){
        if(p.second >0){
            result+=string(p.second,p.first);
        }
      }
        return result;
    }
};