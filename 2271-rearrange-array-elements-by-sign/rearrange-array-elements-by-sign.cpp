class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>pos,neg;

       for(auto ele: nums){
        if(ele >0){
            pos.push_back(ele);
        }

        else{
            neg.push_back(ele);
        }
       }

    //    for(int i=0;i<n/2;i++){
    //     nums[2*i]=pos[i];
    //     nums[2*i + 1]=neg[i];
    //    }

    int p=0,q=0;

    for(int i=0;i<n;i++){
        if(i%2 ==0){
            nums[i]=pos[p];
            p++;
        }
        else{
            nums[i]=neg[q];
            q++;
        }
    }

       

        return nums;
        
    }
};