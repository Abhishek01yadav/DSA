class Solution {
public:
    int minFlips(int a, int b, int c) {
        int temp=a|b;
        int ans=temp^c;
        return __builtin_popcountll(ans)+ __builtin_popcountll(ans& (a&b));
        
    }
};