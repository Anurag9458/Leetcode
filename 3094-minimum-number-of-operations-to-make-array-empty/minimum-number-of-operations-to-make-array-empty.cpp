class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        map<int,int>mp;
        for(int i:nums){
            mp[i]++;
        }
        int ans=0;
        for(auto it:mp){
            int a=it.second;
            if(a==1)return -1;
            // else if(a==2)return ans++;
            else if(a%3)ans+=(a/3+1);
            else if(a%3==0)ans+=a/3;
            
        }
        return ans;
    }
};