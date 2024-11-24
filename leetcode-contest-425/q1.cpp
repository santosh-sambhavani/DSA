class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size(), min = 1001, flag = false;

        for (int windowSize = l; windowSize <= r; windowSize++) {
            // reset for r
            int sum = 0, start = 0, end = windowSize - 1;

            // find sum of first l nums
            for (int i = 0; i < windowSize; i++) {
                sum += nums[i];
            }

            // get minimum out of l size of sub arrays
            while (end < n) {
                if (sum > 0 && sum < min) {
                    min = sum;
                    flag = true;
                }

                sum -= nums[start++];
                sum += (end < n - 1 ? nums[end + 1] : nums[end]);
                end++;
            }
        }

        return flag ? min : -1;
    }
};
