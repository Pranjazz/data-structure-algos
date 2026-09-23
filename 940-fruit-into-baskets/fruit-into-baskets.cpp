class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        unordered_map<int,int> f;
        int low = 0;
        int res = -1;

        for(int high=0;high<fruits.size();high++){
            f[fruits[high]]++;

            while(f.size() > 2){

                f[fruits[low]]--;

                if(f[fruits[low]] == 0){
                    f.erase(fruits[low]);
                }

                low++;
            }

            if(f.size() < 2 || f.size() == 2){
                res = max(res, high - low + 1);
            }
        }

        return res;
        
    }
};