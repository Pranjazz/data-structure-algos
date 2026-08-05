class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int m = intervals.size();

        vector<vector<int>> result;

        for(int i=0;i<m;i++){
            
            //completely before the newinterval
            if( intervals[i][1] < newInterval[0]){
                result.push_back(intervals[i]);
            }
            else if( intervals[i][0] > newInterval[1]){
                result.push_back(newInterval);
                newInterval = intervals[i];
            }
            else {
                newInterval[0]=min(intervals[i][0],newInterval[0]);
                newInterval[1]=max(intervals[i][1],newInterval[1]);
            }
        }
        result.push_back(newInterval);

        return result;
    }
};