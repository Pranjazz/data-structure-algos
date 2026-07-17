class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> f;
        bool flag = false;
        
        for(int i=0;i<= nums.size()-1;i++){
            f[nums[i]]++;
        }
        for(int i=0;i<= nums.size()-1;i++){
            if(f[nums[i]] > 1){
                flag = true;
            }
        }
        return flag;
    }
};