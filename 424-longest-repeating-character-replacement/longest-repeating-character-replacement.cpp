class Solution {
public:
    int characterReplacement(string s, int k) {

        vector<int> f(26,0);
        int left = 0;
        int res=0;
        int maxcnt = 0;

        for(int right =0;right<s.size();right++){

            f[s[right] - 'A']++;

            int len = right - left + 1;
            maxcnt = max(maxcnt ,f[s[right] - 'A'] );

            while(len - maxcnt > k){
                f[s[left]- 'A']--;
                left++;
                len = right - left + 1;
                maxcnt =max( maxcnt , f[s[right] - 'A']);
                
            }
                res = max(res , right-left +1);
        }
        return res;
    }
};