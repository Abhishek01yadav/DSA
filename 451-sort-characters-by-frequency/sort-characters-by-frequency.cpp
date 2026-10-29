class Solution {
public:
 static inline unordered_map<char,int> mp;

    static bool cmp(char a, char b) {
        if (mp[a] != mp[b]) return mp[a] > mp[b];
        return a < b;
    }
    string frequencySort(string s) {
         mp.clear();
        for (char c : s) mp[c]++;
        sort(s.begin(), s.end(), cmp);
        return s;
       
        
      
        
    }
};