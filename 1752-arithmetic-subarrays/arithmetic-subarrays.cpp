class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n=l.size();
        vector<bool>ans;
        for(int i=0;i<n;i++){
            int a=l[i],b=r[i];
            multiset<int>st;
            for(int j=a;j<=b;j++){
                st.insert(nums[j]);
                
            }
            vector<int>v(begin(st),end(st));
            int diff=v[1]-v[0];
            int flag=1;
            for(int i=1;i<v.size();i++){
                if(v[i]-v[i-1]!=diff){
                    ans.push_back(0);
                    flag=0;
                    break;
                }
            }
            if(flag)ans.push_back(1);
        }
        return ans;
    }
};