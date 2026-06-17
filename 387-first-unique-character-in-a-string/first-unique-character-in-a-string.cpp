class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> f;
        for(int i=0;i<=s.size()-1;i++){
            f[s[i]]++;
        }
        for(int i=0;i<=s.size()-1;i++){
            if(f.find(s[i]) != f.end() ){
                if( f[s[i]] == 1){
                    return i;
                }
            }
        }

        return -1;

    }
};