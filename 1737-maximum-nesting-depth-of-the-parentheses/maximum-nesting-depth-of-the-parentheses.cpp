class Solution {
public:
    int maxDepth(string s) {
        int cnt=0;
        int mx=0;
        for(auto ch:s){
            if(ch=='(') 
            {
                cnt++;
            }
            if(ch==')'){
                mx=max(mx,cnt);
                cnt--;
            }
        }
        return mx;
    }
};