/**
 * Author: Xiangyue Cai
 * Date: 2019-09-05
 */

class Solution {
public:
    string digits_arr[8] =
            {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;

    void findCombinations(
        const string &digits, int index, const string &s) {
        
        if (index == digits.length()){
            res.emplace_back(s);
            return;
        }
        string tmp = digits_arr[digits[index] - '0' - 2];
        for (int i = 0 ; i < tmp.length(); ++i) {
            findCombinations(digits, index + 1, s + tmp[i]);
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.size() < 1 || digits.find("1") != string::npos)
            return vector<string>{};

        findCombinations(digits, 0, "");
        return res;
    }
};