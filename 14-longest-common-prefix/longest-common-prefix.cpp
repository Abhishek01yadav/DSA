class Solution {
public:

    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        for(int col=0;col<strs[0].size();col++){
            char ch=strs[0][col];
            for(int k=1;k<n;k++){
                if(strs[k][col] !=ch || col>=strs[k].size()) {
                    return strs[0].substr(0,col);
                }
            }

        }
       

        return strs[0];
    }
};