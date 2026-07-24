class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int,int>> pq;
        int n = points.size();

        for(int i = 0; i < k; i++) {
        int x = points[i][0];
        int y = points[i][1];
        int dist = x*x + y*y;

        pq.push({dist, i});

        }
        for(int i=k;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];
            int dis= x*x+y*y;
            if( dis >= pq.top().first){
                continue;
            }
            pq.pop();
            pq.push({dis,i});

        }

        vector<vector<int>> ans;

        while(!pq.empty()) {
          ans.push_back(points[pq.top().second]);
          pq.pop();
        }
        return ans;
        
    }
};