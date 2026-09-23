class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);

        for(char ch : s1){
            freq1[ch -'a']++;
        }
        for(int i=0;i< s2.size();i++){
            freq2[s2[i] - 'a']++;

            //windowSize exceeds the permuation string
            if(i >= s1.size()){
                freq2[s2[i-s1.size()] - 'a']--;
            }
            //windowSize is equal to the perm string size
            if(i >= s1.size() - 1){
                if(freq1 == freq2){
                    return true;
                }
            }
        }
        return false;
    }
};