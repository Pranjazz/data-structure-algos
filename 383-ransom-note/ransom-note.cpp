class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char,int> f;

        for(char ch : magazine) {
            f[ch]++;
        }

        for(char ch : ransomNote) {

            if(f.find(ch) == f.end() || f[ch] == 0) {
                return false;
            }

            f[ch]--;
        }

        return true;
    }
};