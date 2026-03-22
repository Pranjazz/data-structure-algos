class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low =0;
        int high =0;

        int res =0;
        int minLen = INT_MAX;
        int sum =0;

        for(high =0;high<nums.size();high++){
            sum = sum + nums[high];

            while(sum >= target){
                minLen = min( minLen , high - low+1);
                sum = sum - nums[low];
                low++;
            }
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};