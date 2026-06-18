class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<int,int> f;
        
        for(char ch : text){
            f[ch]++;
        }

        return min({ f['b'],f['a'],f['l']/2,f['o']/2,f['n'] });
        
        
    }
};