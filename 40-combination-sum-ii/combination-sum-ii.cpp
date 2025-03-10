class Solution {
public:
    void combSum(vector<int>& candidates , int index, int target , vector<int> &ds, vector<vector<int>> &ans)
    {
        if(target == 0)
        {
            ans.push_back(ds);
            return;
        }
        for(int i=index;i<candidates.size();i++)
        {
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            ds.push_back(candidates[i]);
            combSum(candidates,i+1,target-candidates[i],ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        combSum(candidates, 0, target, ds, ans);
        return ans;
    }
};