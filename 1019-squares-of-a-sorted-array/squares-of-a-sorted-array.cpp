class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int &i:nums){
            i=pow(i,2);
        }
        sort(begin(nums),end(nums));
        return nums;
    }
};