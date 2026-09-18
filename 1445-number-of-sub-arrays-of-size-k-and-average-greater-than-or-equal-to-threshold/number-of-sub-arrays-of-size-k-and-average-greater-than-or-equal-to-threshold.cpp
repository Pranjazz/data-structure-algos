class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        int n = arr.size();
        int sum =0;
        int count =0;
        
        for(int i=0;i<k;i++){   //first window store
            sum += arr[i];
        }

        int i=0;
        int j=k;
        
        for(j=k;j<n;j++){
            if(sum >= k * threshold){
                count++;
            }
            sum -= arr[i];
            i++;
            sum += arr[j];
        }

        if(sum >= k * threshold){
                count++;
        }

        return count;
    }
};