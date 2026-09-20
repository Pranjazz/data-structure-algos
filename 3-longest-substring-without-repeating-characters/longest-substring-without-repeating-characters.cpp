class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<int,int> f;
        int badiLen =0;

        int low = 0;
        
        for(int high = 0; high<s.size(); high++){
            
            f[s[high]]++;

            while(f[s[high]] > 1){
                f[s[low]]--;

                if(f[s[low]] == 0){
                    f.erase(f[s[low]]);
                }
                low++;
            }

            badiLen = max(badiLen,high - low + 1);

        }
        return badiLen;
    }
};