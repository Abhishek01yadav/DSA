class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit=0;
        int buyprice= prices[0];
        for(int i=1;i<n;i++){
        if( prices[i] < buyprice){
            buyprice=prices[i];
        }
profit=max(profit,prices[i]-buyprice);
        }
        
        

      return profit;
       
    }
   
};