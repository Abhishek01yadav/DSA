class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
         sort(arr.begin(), arr.end(), [](int a, int b) {
            int setbitsofa = __builtin_popcount(a);
            int setbitsofb = __builtin_popcount(b);

            if (setbitsofa == setbitsofb)
                return a < b;   
            return setbitsofa < setbitsofb;     
        });
        return arr;
        
    }
};