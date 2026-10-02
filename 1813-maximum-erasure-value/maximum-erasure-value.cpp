class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum =0;
        int n = nums.size();
        int maxi = INT_MIN;
        unordered_map<int,int> freq;
        int left = 0;
        for(int right = 0;right< n;right++){
            freq[nums[right]]++;
            sum += nums[right];

            while(freq[nums[right]] > 1){
                sum -= nums[left];
                freq[nums[left]]--;
                left++;
            }
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};