class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int ans=0;

        for(int i=0;i<=20;i++){
            int x=0;

            for(int ele:nums){
                int a=(1<<i)&ele;
                x^=a;
            }

            int b=(1<<i)&k;

            if(x!=b)ans++;

        }

        return ans;
    }
};