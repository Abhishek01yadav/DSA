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

        //approach->2

        /********************/
        return n>0 && 1162261467 %n==0;

         /********************/
        
    }
};