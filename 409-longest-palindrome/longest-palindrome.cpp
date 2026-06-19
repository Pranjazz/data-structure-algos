class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        if(n == 1 ){
            return 1;
        }
        unordered_map<char,int> f;
        for(int i=0;i<n;i++){
            f[s[i]]++;
        }
        
        bool odd = false;
        int res =0;

        for(auto i : f){
            int v = i.second;
            if( v % 2 == 0) {
                res += v ;
            }
            else{
                odd = true;
            }

        }

        if( odd == false){
            return res;
        }

        for(auto i:f){
            int v = i.second;
            if(v % 2 != 0){
                res += v-1;
            }
        }
        return res+1;
    }
};