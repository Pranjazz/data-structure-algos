class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()>num[i]&& k>0){
                st.pop();
                k--;
            }
            if(st.empty() && num[i]=='0') continue;
            st.push(num[i]);
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        string str = "";
        while(!st.empty()){
            str+=st.top();
            st.pop();
        }
        reverse(str.begin(), str.end());
        if(str.empty()) return "0";
        else return str;
    }
};