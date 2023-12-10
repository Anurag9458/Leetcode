class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();

        int i=0,j=0;
        double ans=-1e9,temp=0;

        while(i<k){

            temp+=nums[i];
            i++;
        }

        ans=max(temp/k,ans);

        while(i<n){
            temp+=nums[i];
            temp-=nums[j];
            i++;
            j++;
            ans=max(temp/k,ans);
        }
        return ans;
    }
};