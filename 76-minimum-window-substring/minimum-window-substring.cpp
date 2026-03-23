class Solution {
public:
    bool right(vector<int> &need, vector<int> &have){
        for(int i=0;i<256;i++){
            if( have[i] < need[i]){
                return false;
            }
        }
           return true;
    }
    string minWindow(string s, string t) {

        vector<int> need (256,0);
        vector<int> have (256,0);
        int high =0;
        int low =0;
        int res=INT_MAX;
        int start=0;
        int len =high-low+1;

        for(char c : t){
           need[c]++;
        }

        for(high=0;high<s.size();high++){
            have[s[high]]++;

            while(right(need,have)){
                len = high-low+1;
                if(res > len){
                    res = len;
                    start = low;
                }
                have[s[low]]--;
                low++;
            }
        }
        return res == INT_MAX ? "":s.substr(start,res);
    }
};