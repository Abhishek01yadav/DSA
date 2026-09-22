class Solution {
     void f(int idx,int[]candidates,List<Integer>ds,int target,List<List<Integer>>ans){
        int n=candidates.length;
        //base case 
    
            if(target==0){
                ans.add(new ArrayList<>(ds));
            
            return;}
        
        
//picking all indices if it is possible.
        for(int i=idx ; i<n;i++){

            int val=candidates[i];
            if( i > idx && candidates[i] ==candidates[i-1]) continue;

            if(val > target) break;
            
            

            
                ds.add(val);
                f(i+1,candidates,ds,target-val,ans);
                ds.remove(ds.size()-1);
            
               
        }
    
    }
     


    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>>ans=new ArrayList<>();
        List<Integer>ds=new ArrayList<>();
        Arrays.sort(candidates);

        f(0,candidates,ds,target,ans);
        
        return ans;
       
        
    }
}