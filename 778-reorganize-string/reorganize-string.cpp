class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>> pq;

        unordered_map<char,int> f;
        int seat = 0;

        for(char ch : s){
            f[ch]++;
        }

        for(auto i: f){
            pq.push({i.second,i.first});
        }
        
        string res="";

        while(!pq.empty()){
            
            pair<int,char> p = pq.top();
            pq.pop();

            if(seat==0 || res[seat-1]!= p.second){
                res.push_back(p.second);
                p.first--;
                seat++;
                if(p.first>0){
                    pq.push(p);
                }
            }
            else{
                if(pq.empty()){
                    return "";
                }
                pair<int,char> pp =pq.top();
                pq.pop();
                res.push_back(pp.second);
                seat++;
                pp.first--;
                if(pp.first > 0){
                    pq.push(pp);
                }
                    pq.push(p);
            }
        }

        return res;
    }
};