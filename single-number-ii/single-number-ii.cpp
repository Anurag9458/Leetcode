class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0,countodd = 0, counteven =0;
        for(int i = 0;i < 32; i++)
        {
            countodd = 0; counteven = 0;
            for(int j = 0 ;j < nums.size(); j++)
            {
                if((1<<i) & nums[j]){
                    countodd++;
                }
                else{
                    counteven++;
                }
            }
            if(countodd%3){
                ans = ans | (1<<i);
            }
        }
        return ans;
    }
};