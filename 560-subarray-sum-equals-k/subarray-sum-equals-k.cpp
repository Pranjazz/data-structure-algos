class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> f;

        int sum =0;
        int ques = sum - k;
        int ans =0;
        f[0]=1;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            ques = sum-k;
            int freq = f[ques];
            ans+=freq;
            f[sum]++;
        }
        return ans;
    }
};