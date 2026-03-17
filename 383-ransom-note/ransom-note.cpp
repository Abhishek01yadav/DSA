class Solution {
public:
    bool canConstruct(string s, string t) {
        vector<int> freq(26, 0);
        for (char c : t)
            freq[c - 'a']++;
        for (char c : s) {
            if (freq[c - 'a'] == 0)
                return false;
            freq[c - 'a']--;
        }
        return true;
    }
};