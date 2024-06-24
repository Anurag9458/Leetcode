class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0,temp=0;
        vector<int>v(n,0);
        for(int i=0;i<n;i++){
            if(i>=k && v[i-k]){
                temp--;
            }
            if(temp%2==nums[i]){
                if(i+k>n){
                    return -1;
                }
                temp++;
                count++;
                v[i]=1;
            }
        }

       
        return count;
    }
};