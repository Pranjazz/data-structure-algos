class Solution {
public:
   
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left =0;
        int res =0;
        int zeros = 0;


        for(int right = 0;right<n;right++){
            int len = right - left + 1;
            
            if(nums[right] == 0){
                zeros++;
            }
            while(zeros > k ){
                if(nums[left] == 0){
                    zeros --;
                }
                left++;
                len = right -left+1;
            }
            if(zeros < k || zeros == k){
                res = max(res , len);
            }
        }
        return res;
        
    }
};