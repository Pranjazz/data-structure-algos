class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> f;
        
        int low=0;
        int k=2;
        int res = -1;

        for(int high =0;high<fruits.size();high++){

            f[fruits[high]]++;

            while(f.size() > k){

                f[fruits[low]]--;
                
                if(f[fruits[low]] == 0){
                    f.erase(fruits[low]);
                }

                low++;
            }
            if(f.size() == k || f.size() < k){
                res = max(res,high-low+1);
            }
        }
        return res;    

    }
};