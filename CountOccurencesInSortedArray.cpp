class Solution {
   public:
    int countOccurrences(const vector<int>& nums, int target) {
        int first = nums.size();
        int last = nums.size();
        int low = 0;
        int high = nums.size() - 1;
        int count = 0;
        // find first occurence
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                first = mid;
                high = mid - 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else
                low = mid + 1;
        }

        // find last occurence
        low  = 0 ; 
        high = nums.size()-1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                last = mid;
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else
                low = mid + 1;
        }
        if(last == nums.size()) return 0;
        return last - first + 1;
    }
};