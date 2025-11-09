class Solution {
   public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int floor = -1;
        int ceil = -1;
        int low = 0;
        int high = nums.size()-1;
        while (low <= high) {
           int mid = low + (high - low) / 2;
             if (nums[mid] == x) {
                floor = ceil = nums[mid];
                break;
            } 
            else if(nums[mid]>x){
                ceil = nums[mid];
                high = mid-1;
            }
            else if(nums[mid]<x){
                floor = nums[mid];
                low = mid+1;
            }
        }
       return {floor , ceil};
    }
};