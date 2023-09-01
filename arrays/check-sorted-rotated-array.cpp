// problem no. 1752
// check if two consecutive elements matching the condition nums[i] > nums[i+1]
// if this condition matches more than 1 time it's not sorted rotated array 
class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] > nums[i+1]) 
                cnt++;
        }
        if(nums.back() > nums[0])
            cnt++;
        if(cnt > 1) 
            return false;
        return true;
    }
};
