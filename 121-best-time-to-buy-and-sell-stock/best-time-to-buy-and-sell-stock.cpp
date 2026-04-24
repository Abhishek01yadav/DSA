class Solution {
public:
    int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         int profit=0;
//         int buyprice= prices[0];

//         for(int i=1;i<n;i++){
//         if( prices[i] < buyprice){
//             buyprice=prices[i];
//         }
// profit=max(profit,prices[i]-buyprice);
//         }

         int n=prices.size();
        int profit=0;
        int buyprice= prices[n-1];

        for(int i=n-2;i>=0;i--){
        if( prices[i] > buyprice){
            buyprice=prices[i];
        }
profit=max(profit, buyprice -prices[i]);
        }


        
        
        

      return profit;
       
    }
   
};