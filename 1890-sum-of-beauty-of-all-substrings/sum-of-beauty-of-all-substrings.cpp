class Solution {
public:
    int beautySum(string s) {

        int sum = 0;
        int n = s.size();

        // loop through all substrings

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freqmap;
          

            for (int j = i; j < n; j++) {
                freqmap[s[j]]++;


                int mini = INT_MAX;
            int maxi = INT_MIN;

                for (auto ele : freqmap) {

                    maxi = max(maxi, ele.second);
                    mini = min(mini, ele.second);
                }
                 sum+=maxi-mini;
            }
            
        }
        return sum;
    }
};