class Solution {
public:
    int M = 1e9 + 7;
    int concatenatedBinary(int n) {

        long result = 0;
        for (int i = 1; i <= n; i++) {
            int digit = log2(i) + 1; // kisi bhi number me kitne binary digits
                                     // honge ye ye btata hai.
            result = ((result << digit) % M + i) %
                     M; //(yha pr result<<digit) purane number kitne digit ka
                        //hoga ye btayega phir usme agar add kr denge naya
                        //number to phir hume new number mil jayega.
        }
        return result;
    }
};