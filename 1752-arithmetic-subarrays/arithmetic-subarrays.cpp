class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n=nums.size(),m=l.size();
        vector<bool>ans;
        for(int i=0;i<m;i++){
            int a=l[i],b=r[i];
            vector<int>temp;
            for(int j=a;j<=b;j++){
                temp.push_back(nums[j]);
            }

            sort(begin(temp),end(temp));

            int diff=temp[1]-temp[0];
            int flag=0;
            for(int k=1;k<temp.size();k++){
                if(diff!=temp[k]-temp[k-1]){
                    flag=1;break;
                }
            }
            if(flag){
                ans.push_back(0);
            }else{
                ans.push_back(1);
            }
        }


        return ans;

    }
};