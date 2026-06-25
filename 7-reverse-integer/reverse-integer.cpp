class Solution {
public:
    int reverse(int x) {
        int revx=0;
        while(x!=0){
            int lastdigit=x%10;
            if(revx >INT_MAX/10 ||  revx <INT_MIN/10){
                return 0;
           
            }
          revx=revx*10+lastdigit;
            x/=10;

        }
       // if(revx> INT_MAX || revx<INT_MIN) return 0;
        return revx;
    }
};