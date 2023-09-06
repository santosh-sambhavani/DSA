// leetcode 125
class Solution {
private:
    char lowercase(char ch) {
        if(ch >= 'A' && ch <= 'Z') {
            cout << char('a' + (ch - 'A'))<< " "; 
            return char('a' + (ch - 'A'));   
        }
        // cout << ch << " ";
        return ch;
    }
    
    bool isValid(char ch) {
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
            return true;
        return false;
    }
    
public:
    bool isPalindrome(string s) {
        if(s.size() == 1) return true;
        int start = 0, end = s.size() - 1;
        while(start < end) {
            cout << start << " || " << end << " validity: " 
                << isValid(s[start]) << isValid(s[end]) << " >> ";
            while((start < end) &&!isValid(s[start])) { start++; }
            while((start < end) &&!isValid(s[end])) { end--; };
            cout << start << " || " << end << " >> ";
            if((start < end) && (lowercase(s[start++]) != lowercase(s[end--]))) return false;
            cout << "\n";
        }
        return true;
    }
};
