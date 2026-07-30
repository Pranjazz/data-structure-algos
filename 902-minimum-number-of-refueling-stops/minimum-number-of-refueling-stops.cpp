class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();

        priority_queue<int> pq;
        int i=0;
        int stops=0;

        while(startFuel < target){

            while( i < stations.size() && stations[i][0] <= startFuel){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty()){
                return -1;
            }

            startFuel += pq.top();
            pq.pop();
            stops++;

        }
        return stops;
    }
};