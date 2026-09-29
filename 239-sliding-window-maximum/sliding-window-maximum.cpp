class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        priority_queue<pair<int,int>> pq;

        int low = 0;
        int high =0;

        for(high = 0;high < nums.size();high++){

            pq.push({nums[high],high});
            while(pq.top().second < low){
                pq.pop();
            }

            if(high - low + 1 >= k){
                ans.push_back({pq.top().first});
                low++;
            }
        }
        return ans;
    }
};