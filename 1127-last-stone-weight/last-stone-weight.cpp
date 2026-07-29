class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }

        while(pq.size() > 1){
            int p = pq.top();
            pq.pop();
            int q = pq.top();
            pq.pop();
            int diff= abs(p-q);

            pq.push(diff);
        }

        if(pq.size() == 1) return pq.top();
        return -1;
    }
};