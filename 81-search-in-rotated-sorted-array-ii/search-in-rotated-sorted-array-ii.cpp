class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;

        while(low <= high){
            int mid=low+(high-low)/2;

            if(nums[mid]==target){
                return true;
            }


            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low++;
            high--;
            continue;
        }
           
//check if the left half is sorte
            if( nums[low] <=nums[mid]){
               
// If target lies in the sorted left half, search there
                if(target>=nums[low] && target <nums[mid]){
                    high=mid-1;
                }
// move to the right half 
                else{
                    low=mid+1;
                }

            }
       

//otherwise
        else
        {

        // If target lies in the sorted right half, search there    
            if(target>nums[mid] && target<=nums[high])
            {
            low=mid+1;
            }

           // move to the left half
            else{
                high=mid-1;
            }

        }
        }
    
return false;
        
    }
};