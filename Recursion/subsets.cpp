class Solution {
    
private: 
    void generateCombinations(
        vector<int> nums, int index, vector<int> output, vector<vector<int>>& result
    ) {
        
        if (index == nums.size()) {
            result.push_back(output);
            return ;
        }
        
        // Ignore element for one variation of subset
        generateCombinations(nums, index+1, output, result);
        
        // Include element for other variation of subset
        output.push_back(nums[index]);
        generateCombinations(nums, index+1, output, result);
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        generateCombinations(nums, 0, {}, result);
        return result;   
    }
};
