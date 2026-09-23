class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int low = 0;
        bool flag = false;

        unordered_map<int,int> f ,windows;
        for(int i=0;i< s1.size();i++){
            f[s1[i]]++;
        }

        for(int high = 0;high<s2.size();high++){
            
            windows[s2[high]]++;

            if( high - low + 1 > s1.size()){
                windows[s2[low]]--;
                
                if(windows[s2[low]] == 0){
                    windows.erase(s2[low]);
                }
                low++;
            }

            if(high - low + 1 == s1.size()){
                if(windows == f){
                    return true;
                }
            }
        }
        
        return false;
    }
};