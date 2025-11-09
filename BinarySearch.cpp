class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mid = low + (high-low)/2;
        while(low<=high){
            if(nums[mid]== target) return mid;
            else if(nums[mid]>target){
                high = mid-1;
                mid = low + (high-low)/2;
            }
            else{
             low = mid+1;
             mid = low + (high-low)/2;
            }
        }
        return -1;
    }
};