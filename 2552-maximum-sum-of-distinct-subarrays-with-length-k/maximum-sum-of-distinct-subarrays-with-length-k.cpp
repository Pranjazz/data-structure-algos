class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> f;
        int n = nums.size();
        long long sum =0;

        for(int i=0;i<k;i++){   //saving frequencies in map and storing the first window
            sum+= nums[i];
            f[nums[i]]++;
        }

        int i =0;
        int j = k;
        long long maxi = 0;

        if(f.size() == k){

            maxi = sum;
        }

        while(j<n){

            sum -= nums[i];
            f[nums[i]]--;

            if(f[nums[i]] == 0){
                f.erase(nums[i]);
            }

            sum += nums[j];
            f[nums[j]]++;

            if (f.size() == k) {
                maxi = max(maxi, sum);
            }
            i++;
            j++;
        }

        return maxi;
    }
};