class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        priority_queue<pair<int,int>> pq; //max heap
        int n=arr.size();

        for(int i=0;i<k;i++){
            int value=arr[i];
            pair<int,int> curr = {abs(value-x) , value};
            pq.push(curr);
        }

        for(int i=k;i<n;i++){
            int value = arr[i];
            int diff= abs(value-x);
            pair<int,int> curr ={diff,value}; 

            if(curr.first < pq.top().first ||
            (curr.first == pq.top().first && curr.second < pq.top().second)){
                pq.pop();
                pq.push(curr);
            }
        }

        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        sort(res.begin(),res.end());
        return res;
    }
};