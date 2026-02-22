class Solution {
public:
    int binaryGap(int n) {
        string s = bitset<32>(n).to_string();
        s = s.substr(s.find('1'));
        int len = s.size();
        int ans=0;
        int maxi=0;
      
      int last = -1;
       

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                if (last != -1) {
                    maxi = max(maxi, i - last);
                }
                last = i;
            }
        }
       
       
       
      
       
        
       
        return maxi;
    }
};