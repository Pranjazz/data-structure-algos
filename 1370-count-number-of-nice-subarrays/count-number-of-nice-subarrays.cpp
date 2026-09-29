
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

    int atMost(vector<int>& nums, int k) {
        int low = 0;
        int high = 0;
        int count = 0;
        int sum = 0;

        while (high < nums.size()) {
            sum += nums[high] % 2;

            while (sum > k) {
                sum -= nums[low] % 2;
                low++;
            }

            count += high - low + 1;
            high++;
        }

        return count;
    }
};