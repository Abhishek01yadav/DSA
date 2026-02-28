class Solution {
public:
    int M = 1e9 + 7;
    int concatenatedBinary(int n) {
        int digits=0;

        long result = 0;
        for (int num = 1; num <= n; num++) {
            if((num & num-1)==0) digits++; // kisi bhi number me kitne binary digits
                                     // honge ye ye btata hai.
            result = ((result << digits) % M + num) %M;
                      //(yha pr result<<digit) purane number kitne digit ka
                        //hoga ye btayega phir usme agar add kr denge naya
                        //number to phir hume new number mil jayega.
        }
        return result;
    }
};