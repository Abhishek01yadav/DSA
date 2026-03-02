class Solution {
public:
    bool isPowerOfThree(int n) {

        // method -1 via recursion tc=> o(log3n) sc=>o(log3n)
        /*********************/

        // if(n==0) return false;
        // if(n==1) return true;
        // if(n%3==0){
        //     return  isPowerOfThree(n/3); 
        // }
        // return false;

        /*********************/

        //approach->2 32 bit ka signed integer sabse bda jo 3 se divide ho wo hai 3 ki poer 19 if this number is divisble by this value so definetly is is a power of three.

        /********************/
       // return n>0 && 1162261467 %n==0;

         /********************/

         // Approach->3 iterative 


          /********************/
          if(n<=0) return false ;
          while(n%3==0){
            n=n/3;
          }
          return n==1;

        
    }
};