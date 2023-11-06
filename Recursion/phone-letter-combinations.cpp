// Leetcode problem 17
class Solution {
private:
    void generateCombinations(
        string digits, 
        int index, 
        vector<string> mapper, 
        string output, 
        vector<string>& result
    ) {
        if(index == digits.size()) {
            result.push_back(output);
            return ;
        }
        string str = mapper[int(digits[index] - '0')];
        for(int j = 0; j < str.size(); j++) {
            output += str[j];
            generateCombinations(digits, index+1, mapper, output, result);
            output = output.substr(0,output.length()-1);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.size() == 0) {
            return result;   
        }
        vector<string> mapper {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        generateCombinations(digits, 0, mapper, "", result);
        return result;
    }
};
