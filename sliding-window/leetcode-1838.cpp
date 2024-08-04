// 1838. Frequency of the Most Frequent Element
// https://leetcode.com/problems/frequency-of-the-most-frequent-element/

// first of all sort the array
// use the sliding window. and keep expanding the window untill it's valid.
// valid means (total of the window elemnts + k >= number of elements in window * arr[right]) considering we want to make every element of window = arr[right]
// just note the max win len while full iteration over array

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // left, right, total, winLen, ans
        long long left = 0, 
            right = 0, 
            sum = 0,
            ans = 0;
        
        sort(nums.begin(), nums.end());
        
        // loop while right <n
        while (right < nums.size()) {
            
            sum += nums[right];

            // move left if window is invalid
            while((right - left + 1) * nums[right] > sum + k) {
                sum -= nums[left];
                left++;
            }
            
            ans = max(ans, (right - left + 1));
            right++;
        }
        
        return ans;
    }
};

// [1,2,4]
// 5

// [1,4,8,13]
// 5
