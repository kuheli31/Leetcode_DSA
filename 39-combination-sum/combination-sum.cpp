class Solution {
public:
    void combSum(vector<int>& candidates , int index, int target , vector<int> &ds, vector<vector<int>> &ans)
    {
        int n = candidates.size();
        if(index >= n)
        {
            if(target == 0)
            {
                ans.push_back(ds);
            }
            return;
        }

        // Pick elements
        if(candidates[index] <= target)
        {
            ds.push_back(candidates[index]);
            combSum(candidates, index, target - candidates[index], ds, ans);
            ds.pop_back();
        }

        // Not pick elements
        combSum(candidates, index + 1, target, ds, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int> ds;
        combSum(candidates, 0, target, ds, ans);
        return ans;
    }
};
