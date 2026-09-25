class Solution {
    void f(int idx,int[] nums,List<List<Integer>>ans){
        int n=nums.length;
        if(idx==n){
           List<Integer>ds=new ArrayList<>();
           for(int i=0;i<n;i++){
            ds.add(nums[i]);
           }
           ans.add(new ArrayList<>(ds));
            return;
        }

        for(int i=idx;i<n;i++){
            swap(i,idx,nums);
            f(idx+1,nums,ans);
            swap(i,idx,nums);
        }

    }

    void swap(int i,int j,int[]nums){
        int t=nums[i];
        nums[i]=nums[j];
        nums[j]=t;
    }

    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>>ans=new ArrayList<>();
        f(0,nums,ans);
        return ans;
        
    }
}