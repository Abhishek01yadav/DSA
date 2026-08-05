class Solution {
public:


bool ispossible(vector<int>& weights, int days, int capacity) {
    int currentLoad = 0;
    int requiredDays = 1;

    for (int weight : weights) {
        if (currentLoad + weight > capacity) {
            requiredDays++;
            currentLoad = weight;
        } else {
            currentLoad += weight;
        }
    }

    return requiredDays <= days;
}

    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
int ans=-1;
        while(low <= high){
            int mid=low+(high-low)/2;
            if(ispossible(weights,days,mid)){
                ans=mid;
                high=mid-1;

                
            }
            else {
                low=mid+1;
            }
            


        }

        
        return ans;
    }
};