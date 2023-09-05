// Problem no. 567
class Solution {
private:
    bool compareCount(vector<int> v1, vector<int> v2) {
        for(int i = 0; i < 26; i++) {
            if(v1[i] != v2[i]) return false;
        }
        return true;
    }
    
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> count_s1(26, 0), count_s2(26, 0);
        for(int i = 0; i < s1.size(); i++) {
            count_s1[s1[i] - 'a']++;
        }
        int winSize = s1.size();
        for(int i = 0; i < winSize; i++) {
            count_s2[s2[i] - 'a']++;
        }
        
        int start = 0, end = winSize - 1;
        while(end < s2.size()) {
            if(compareCount(count_s1, count_s2)) return true;
            if(++end < s2.size()) {
                count_s2[s2[start] - 'a']--;
                start++;
                count_s2[s2[end] - 'a']++;      
            }
        }
        return false;
    }
};
