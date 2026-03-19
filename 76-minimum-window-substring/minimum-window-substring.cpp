class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        unordered_map<char, int> mp;
        for (auto ch : t) {
            mp[ch]++;
        }
        int i = 0, j = 0;
        int start = 0;
        int minlen = INT_MAX;
        int count = mp.size();
        while (j < n) {
            if (mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;
                if (mp[s[j]] == 0)
                    count--;
            }

            if (count == 0) {
                while (count == 0) {
                   if(j-i+1 < minlen){
                    minlen=j-i+1;
                    start=i;
                   }
                
                if (mp.find(s[i]) != mp.end()) {
                    mp[s[i]]++;
                    if (mp[s[i]] > 0)
                        count++;
                }
                i++;
                }
            }
            j++;
        }
        if (minlen == INT_MAX)
            return "";
        return s.substr(start, minlen);
    }
};