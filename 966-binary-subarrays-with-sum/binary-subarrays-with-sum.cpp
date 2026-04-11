class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map <int ,int> f;
        int n = nums.size();
        int sum =0;
        int redsum = 0;
        int ans=0;
        f[0]=1;
        for(int i=0;i<n;i++){
            sum += nums[i];
            redsum = sum - goal;
            ans += f[redsum];
            f[sum]++;
        }

        return ans;
    }
};