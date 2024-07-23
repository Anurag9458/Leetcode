class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>mp;
        for(int i:nums){
            mp[i]++;
        }
        
        vector<int>ans;

        map<int,vector<int>>v;

        for(auto it:mp){
            v[it.second].push_back(it.first);
        }

        for(auto it:v){
            int a=it.first;
            vector<int>temp=it.second;
            sort(begin(temp),end(temp),greater<int>());
            for(int i:temp){
                int b=a;
                while(b--)
                ans.push_back(i);
            }
        }

        return ans;
    }
};