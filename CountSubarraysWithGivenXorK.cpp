class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int preXOR = 0;
        int count = 0;
        unordered_map<int,int>mpp;
        mpp[0] = 1;
        for(int i = 0;i<nums.size();i++){
             preXOR^=nums[i];
            if(mpp.find(preXOR^k)!=mpp.end()){
                count+=mpp[preXOR^k];
            }
            mpp[preXOR]++;
        }
        return count;
    }
};