class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int ans=0;

        for(int i=0;i<n-2;i++){
            int diff=nums[i+1]-nums[i];
            int count=1;
            for(int j=i;j<n-1;j++){
                if(nums[j+1]-nums[j]==diff){
                    count++;
                    if(count>=3)ans++;
                }else break;
                
            }
        }

        return ans;
    }
};