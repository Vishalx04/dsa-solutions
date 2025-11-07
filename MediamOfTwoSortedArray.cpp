// brute - 

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (nums1[i] <= nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            } else {
                merged.push_back(nums2[j]);
                j++;
            }
        }
        while (i < n1) {
            merged.push_back(nums1[i]);
            i++;
        }
        while (j < n2) {
            merged.push_back(nums2[j]);
            j++;
        }
        if (merged.size() % 2 == 0)
            return (merged[merged.size() / 2] + merged[merged.size() / 2 - 1]) /
                   2.0;
        else
            return merged[merged.size() / 2];
    }
};