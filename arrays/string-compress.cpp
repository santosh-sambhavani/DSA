// leet code problem 443
/*
manage three pointers 
  - one for insertion  i here
  - one for current  j here 
  - one to find results as a reference  tempIndex here
*/
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), i = 0, j = 0;
        cout << n;
        while(j < n) {
            char temp = chars[j];
            int tempIndex = j;
            while(j < n && temp == chars[j]) {
                j++;
            }
            chars[i++] = temp;
            if(j - tempIndex > 1) {
                string count = to_string(j - tempIndex);
                for(char ch: count) {
                    chars[i++] = ch;
                }   
            }
        }
        return i;
    }
};
