class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        int temp=(n*(n+1))/2;

        for(int i:nums){
            sum+=i;
        }

        return temp-sum;


    }
};