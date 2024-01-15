class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
         map<int,int>mp1,mp2;
        for(vector<int>v:matches)
        {
            mp1[v[0]]++;mp2[v[1]]++;
        }
        vector<vector<int>>ans;
        vector<int>temp1,temp2;
        for(auto it:mp1)
            if(!mp2.count(it.first))temp1.push_back(it.first);
        for(auto it:mp2)
            if(it.second==1)temp2.push_back(it.first);
        ans.push_back(temp1);
        ans.push_back(temp2);
        return ans;
    }
};