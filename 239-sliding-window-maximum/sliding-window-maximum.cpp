class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>dq;
        vector<int>res;

        for(int i=0;i<n;i++){

            // 1)maintain a valid window
            while(!dq.empty() && dq.front() <=i-k){
                dq.pop_front();
            }

            //2) maintain monotonicity

            while(!dq.empty() && nums[i] > nums[dq.back()]){
                dq.pop_back();
            }

            // 3)now push current element
            dq.push_back(i);

            //4)storing result
            if(i>=k-1){
                res.push_back(nums[dq.front()]);
            }






        }
        return res;
        
    }
};