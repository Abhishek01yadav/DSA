class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        // int n = nums.size();
        // int st = 0, end = n - 1;
        // int res1 = -1, res2 = -1;
        // while (st <= end) {
        //     if (nums[st] == target) {
        //         res1 = st;
        //     }

        //     if (nums[end] == target) {
        //         res2 = end;
        //     }

        //     st++;
        //     end--;
        // }
        // return {res1, res2};

        int n = nums.size();

        int low = 0, high = n - 1;
        int res1 = -1, res2 = -1;


// finding first occurence
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                res1 = mid;
                high = mid - 1;

            } 
             else if (nums[mid] > target) {
                
                high= mid - 1;
            }
            else

            {
                low = mid + 1;
            }
        }


//finding last occurence
         low = 0, high = n - 1;
 
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                res2 = mid;
                low=mid+1;
              

            } 

            else if (nums[mid] < target) {

                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }

        return {res1, res2};
    }
};