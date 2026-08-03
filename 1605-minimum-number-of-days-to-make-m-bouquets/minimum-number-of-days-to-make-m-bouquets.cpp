class Solution {
public:
bool ispossible(vector<int>& bloomday,int day, int m, int k){
    int count =0;
    int noB=0;
    for(auto bloom : bloomday){
        if(bloom  <= day){// particular flower bloom hua hai ya nhi
            count++;
            
            // if(count==k){
            //     bouqets++;// ek possible bouqet mil gya 
            //     count=0;
            // }
        }
        else{
             noB+=(count/k);
            count=0;
        }
       


    }
    noB+=(count/k);
    return noB >= m;
    }

    int minDays(vector<int>& bloomday, int m, int k) {
        long long totalflowers=1LL* m *k;

        if(totalflowers > bloomday.size()) return -1;//sabhi flower bloom hoke bhi nhi bna sakte

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



        
       return  low;
    }
};