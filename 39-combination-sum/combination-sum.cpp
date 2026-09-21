class Solution {
public:
    void f(int idx, vector<int>& candidates, vector<int>& temp, int target,
           vector<vector<int>>& result) {
      
        if (idx  < 0) {
            if (target  == 0) {
                result.push_back(temp);  
            }
            return;
        }

        // pick

        if (target >= candidates[idx]) {

            temp.push_back(candidates[idx]);
            f(idx, candidates, temp, target - candidates[idx], result);

            temp.pop_back();
        }

        f(idx - 1, candidates, temp, target, result);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        int n = candidates.size();
        f(n - 1, candidates, temp, target, result);
        return result;
    }
};