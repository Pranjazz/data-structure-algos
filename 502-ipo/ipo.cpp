class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        priority_queue<int> pq;
        vector<pair<int,int>> v;

        for(int i=0;i<capital.size();i++){
            v.push_back({capital[i],profits[i]});
        }

        sort(v.begin(),v.end());
        int idx=0;

        while(k--){
            while(idx < v.size()){
                if(v[idx].first > w) break;
                pq.push(v[idx].second);
                idx++;
            }
            if(pq.empty()) return w;
            w = w + pq.top();
            pq.pop();
        }
        return w;
    }
};