class Solution {
public:
    void fun(string &digits, int index, string &diary,
             vector<string> &res,
             unordered_map<char,string> &f) {

        if(index == digits.size()) {
            res.push_back(diary);
            return;
        }

        string choice = f[digits[index]];

        for(int j = 0; j < choice.size(); j++) {
            diary.push_back(choice[j]);
            fun(digits, index + 1, diary, res, f);
            diary.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        unordered_map<char,string> f;
        vector<string> res;

        if(digits.empty())
            return res;

        f['2']="abc";
        f['3']="def";
        f['4']="ghi";
        f['5']="jkl";
        f['6']="mno";
        f['7']="pqrs";
        f['8']="tuv";
        f['9']="wxyz";

        string diary = "";

        fun(digits, 0, diary, res, f);

        return res;
    }
};