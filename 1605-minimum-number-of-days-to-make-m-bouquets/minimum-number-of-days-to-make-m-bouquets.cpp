class Solution {
public:
bool ispossible(vector<int>& bloomday,int day, int m, int k){
    int count =0;
    int bouqets=0;
    for(auto bloom : bloomday){
        if(bloom  <= day){
            count++;
            if(count==k){
                bouqets++;
                count=0;
            }
        }
        else{
            count=0;
        }


    }
    return bouqets >= m;
    }

    int minDays(vector<int>& bloomday, int m, int k) {
        long long totalflowers=1LL* m *k;

        if(totalflowers > bloomday.size()) return -1;
        int low= *min_element(bloomday.begin(),bloomday.end());
        int high= *max_element(bloomday.begin(),bloomday.end());
int ans=-1;
        
        while(low <= high){
            int mid=low+(high-low)/2;
            if(ispossible(bloomday,mid,m,k)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }



        
       return  ans;
    }
};