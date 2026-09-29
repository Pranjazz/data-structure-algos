class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k-1);
    }

    int atmost(vector<int>& nums, int k){
        unordered_map<int,int> f;
        int low = 0;
        int high = 0;
        int count = 0;

        for(high =0;high < nums.size();high++){
            f[nums[high]]++;

            while( f.size() > k){
                f[nums[low]]--;
                if(f[nums[low]] == 0){
                    f.erase(nums[low]);
                }
                low++;
            }

            count = count + high - low ;

        }
        return count;
    }
};