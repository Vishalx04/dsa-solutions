// brute - use nested loops - will exceed time limit

// optimal - 

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        int n = arr.size();
        int prefixSum = 0;
        unordered_map<int,int>mpp;
        int maxLength = 0;
        for(int i =0 ;i<n;i++){
          
          prefixSum+=arr[i];
          if(prefixSum==0) maxLength = i+1;
          if(mpp.find(prefixSum)!=mpp.end()){
            maxLength = max(maxLength ,i- mpp[prefixSum]);
          }
          else mpp[prefixSum] = i;
        }
        return maxLength;
    }
};