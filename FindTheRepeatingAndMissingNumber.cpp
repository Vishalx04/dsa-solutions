class Solution {
   public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int repeating = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) {
                repeating = abs(nums[i]);
                break;
            } else {
                nums[idx]*=-1;
            }
        }
        int missing = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                missing = i+1;
            }
        }
        return {repeating, missing};
    }
};