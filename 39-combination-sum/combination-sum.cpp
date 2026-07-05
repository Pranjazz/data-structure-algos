class Solution {
public:
    void fun(vector<int> &candidates,int i,int target,vector<int> &choice,vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(choice); return;
        }
        if(i == candidates.size() || target < 0){
            return;
        }

            choice.push_back(candidates[i]);
            fun(candidates,i,target - candidates[i],choice,ans);
            choice.pop_back();
        
            fun(candidates,i+1,target,choice,ans);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> choice;
        vector<vector<int>> ans;
        fun(candidates,0,target,choice,ans);
        return ans;
    }
};