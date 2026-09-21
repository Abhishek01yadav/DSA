class Solution {
    static void f(int idx,int[] candidates, List<Integer>temp,int target, List<List<Integer>>ans){
        int n=candidates.length;
        if(idx==n){
            if(target == 0){
                ans.add(new ArrayList<>(temp));
            }
            return;
        }

        //pick

        int val=candidates[idx];
        if(val <= target){
            temp.add(val);
            f(idx,candidates,temp,target-val,ans);
            temp.remove(temp.size()-1);
        }
        f(idx+1,candidates,temp,target,ans);

    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>>ans =new ArrayList<>();
        List<Integer>temp=new ArrayList<>();
        
        f(0,candidates,temp, target,ans);
        return ans;
        
        
    }
}