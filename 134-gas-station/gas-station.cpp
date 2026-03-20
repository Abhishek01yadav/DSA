class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum=0,ans=0;
        int gsum=accumulate(gas.begin(),gas.end(),0);
         int csum=accumulate(cost.begin(),cost.end(),0);
         if(gsum<csum) return -1;
         for(int i=0;i<gas.size();i++){
            sum+=gas[i]-cost[i];
            if(sum<0){
                sum=0;
                ans=i+1;
            }
         }

        return ans;
    }
};