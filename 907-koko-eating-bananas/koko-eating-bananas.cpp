class Solution {
public:
long long requiredhours(vector<int>& piles, int hourly){
    long long  ans=0;
    for(int i=0;i<piles.size();i++){
        ans+=ceil( (double)piles[i]/hourly);

    }
    
return ans;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());

        while(low <= high)
        {
            int mid=low+(high-low)/2;

            long long  ans=requiredhours(piles,mid);


            if(ans <= h){
               
               high=mid-1;
            }

            else {
               low=mid+1;
            }




        }

        




        return  low;
        
    }
};