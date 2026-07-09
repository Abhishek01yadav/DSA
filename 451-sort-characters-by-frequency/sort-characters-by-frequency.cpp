class Solution {
public:
    string frequencySort(string s) {
       unordered_map<char,int>mp;

        for(auto ele:s){
            mp[ele]++;
        }

       vector< pair<int,char>>p;

        for(auto x:mp){
            p.push_back({x.second,x.first});

        }

        sort(p.rbegin(),p.rend());
        string ans="";

        for(auto it:p){
            while(it.first --){
                ans+=it.second;
            }
        }



        return ans;
    }
};